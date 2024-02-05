//======================================================================
// Son Nguyen
// January 2024
// This program compute the arrival time. the program reads inputs
// about a departure time and the total trip duration time, the program
// will compute and print to the screen the arrival time in the same
// local time as you departure time. If your arrival time is past midnight,
// the ouput will display: "+1".
//======================================================================

#include <iostream>
#include <string>
using namespace std;

int arrivalTime(int departureHour, int departureMinute, int tripDurationHour, int tripDurationMinute, string timeIndication);

int main()
{
    //variable for departure time, trip duration, and time (AM/PM)
    string departureTime, tripDuration, timeIndication; 

    // hour and minute in departure time and trip duration
    int departureHour, departureMinute, tripDurationHour, tripDurationMinute; 

    cout << "Enter departure time (the format is HOUR:MINUTE AM/PM): ";
    getline(cin, departureTime);
    cout << "Enter the trip duration (the format is HOUR:MINUTE): ";
    cin >> tripDuration;

    //get the hour from departure time and convert to integer
    departureHour = stoi(departureTime.substr(0, departureTime.find(":"))); 

    // get the minute and convert to integer
    departureMinute = stoi(departureTime.substr(departureTime.find(":") + 1)); 

    //get the AM/PM part of departure time
    timeIndication = departureTime.substr(departureTime.find("M") - 1, departureTime.find("M") + 1); 

    //get the hour of trip duration and convert to integer
    tripDurationHour = stoi(tripDuration.substr(0, tripDuration.find(":"))); 

    //get the minute of trip duration and convert to integer
    tripDurationMinute = stoi(tripDuration.substr(tripDuration.find(":") + 1)); 

    arrivalTime(departureHour, departureMinute, tripDurationHour, tripDurationMinute, timeIndication);
}

//======================================================================
// arrivalTime
// Given hour and minute of departure time and trip duration. this functions compute the arrival time
// Parameters:
//  departureHour: positive integer between 0 and 11
//  departureMinute: positive integer between 0 and 59
//  tripDurationHour: positive integer
//  tripDurationMinute: positive integer
//  timeIndication: string either "AM" or "PM"
// Return Value:
//  0 if the function runs successfully.
//  The function prints to the screen
//======================================================================
int arrivalTime(int departureHour, int departureMinute, int tripDurationHour, int tripDurationMinute, string timeIndication)
{
    if (timeIndication == "PM")
    {
        departureHour += 12;
    }

    //if minutes >= 60, convert to hours.
    tripDurationHour += (tripDurationMinute / 60); 
    tripDurationMinute %= 60;

    //count number of days has passed
    int dayPassed = 0; 
    
    //if minutes >= 60, convert to hours.
    int arrivalMinute = (tripDurationMinute + departureMinute) % 60; 
    int arrivalHour = tripDurationHour + departureHour + (tripDurationMinute + departureMinute) / 60;

    //if arrive at first half of the day, time is AM
    if ((arrivalHour / 12) % 2 == 0) 
    {
        timeIndication = "AM";
    }
    //if arrive at second half of the day, time is PM
    else 
    {
        timeIndication = "PM";
        arrivalHour -= 12;
    }

    //count number of days has passed
    while (arrivalHour > 24) 
    {
        arrivalHour -= 24;
        dayPassed++;
    }

    cout << "The arrival time is " << arrivalHour << ":" << arrivalMinute << timeIndication;
    
    //adding +days if arrival is past midnight
    if (dayPassed > 0) 
    {
        cout << " +" << dayPassed << endl;
    }
    else
    {
        cout << endl;
    }

    return 0;
}