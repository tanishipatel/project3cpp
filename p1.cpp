#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

public:
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    virtual void display()
    {
        cout << "\nID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

int Vehicle::totalVehicles = 0;


// Single Inheritance
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() {}

    void inputCar()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;

        cin.ignore();

        cout << "Enter Manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter Model: ";
        getline(cin, model);

        cout << "Enter Year: ";
        cin >> year;

        cin.ignore();

        cout << "Enter Fuel Type: ";
        getline(cin, fuelType);
    }

    void display()
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};


// Multilevel Inheritance
class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    void inputElectricCar()
    {
        inputCar();

        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }

    void display()
    {
        Car::display();
        cout << "\nBattery Capacity: "
             << batteryCapacity;
    }
};


// Multilevel Inheritance
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    void inputSportsCar()
    {
        inputElectricCar();

        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: "
             << topSpeed << " km/h";
    }
};


// Multiple Inheritance Base
class Aircraft
{
protected:
    int flightRange;

public:
    void inputAircraft()
    {
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }

    void displayAircraft()
    {
        cout << "\nFlight Range: "
             << flightRange << " km";
    }
};


// Multiple Inheritance
class FlyingCar : public Car, public Aircraft
{
public:
    void inputFlyingCar()
    {
        inputCar();
        inputAircraft();
    }

    void display()
    {
        Car::display();
        displayAircraft();
    }
};


// Hierarchical Inheritance
class Sedan : public Car
{
};

class SUV : public Car
{
};


class VehicleRegistry
{
private:
    Car cars[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle()
    {
        cars[count].inputCar();
        count++;
    }

    void displayVehicles()
    {
        if(count == 0)
        {
            cout << "\nNo Vehicles Found";
            return;
        }

        for(int i = 0; i < count; i++)
        {
            cout << "\n----------------";
            cars[i].display();
            cout << "\n----------------";
        }
    }

    void searchVehicle(int id)
    {
        for(int i = 0; i < count; i++)
        {
            if(cars[i].getVehicleID() == id)
            {
                cars[i].display();
                return;
            }
        }

        cout << "\nVehicle Not Found";
    }
};


int main()
{
    VehicleRegistry vr;

    int choice, id;

    do
    {
        cout << "\n\n===== VEHICLE REGISTRY SYSTEM =====";
        cout << "\n1. Add Vehicle";
        cout << "\n2. View All Vehicles";
        cout << "\n3. Search Vehicle By ID";
        cout << "\n4. Total Vehicle Objects";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                vr.addVehicle();
                break;

            case 2:
                vr.displayVehicles();
                break;

            case 3:
                cout << "\nEnter Vehicle ID: ";
                cin >> id;
                vr.searchVehicle(id);
                break;

            case 4:
                cout << "\nTotal Vehicle Objects: "
                     << Vehicle::getTotalVehicles();
                break;

            case 5:
                cout << "\nProgram Ended";
                break;

            default:
                cout << "\nInvalid Choice";
        }

    } while(choice != 5);

    return 0;
}