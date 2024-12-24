#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cassert>


/*
* Implement the calculateArea method for the Rectangle class so that the area is calculated as width * height.
Implement the calculateArea method for the Circle class so that the area is calculated as π * radius^2.
Handle errors for incorrect parameter values ​​(width, height, radius).

Expected work results!!!!
For a Rectangle with parameters width = 5, height = 10, the area is 50.
For a Circle with radius = 7, the area is approximately 153.938.
Incorrect parameters (width = -5, radius = 0) throw corresponding errors.
*/
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;

    virtual double calculateArea() const = 0;

    virtual void displayInfo() const {
        cout << "Shape: No specific information\n";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double calculateArea() const override {
        if (width == 0 || height == 0) { // implement the log
            throw logic_error("Invalid dimensions for Rectangle.");
        }
        // implement the log
        throw logic_error("Rectangle area logic is not implemented.");
    }

    void displayInfo() const override {
        cout << "Rectangle: Width = " << width << ", Height = " << height << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        if (radius == 0) { // implement the log
            throw logic_error("Invalid radius for Circle.");
        }
        // implement the log
        throw logic_error("Circle area logic is not implemented.");
    }

    void displayInfo() const override {
        cout << "Circle: Radius = " << radius << endl;
    }
};

// Test methods
void tests() {
    Rectangle rect(5, 10);
    assert(rect.calculateArea() == 50);

    Circle circle(7);
    assert(abs(circle.calculateArea() - 153.938) < 0.001);

    // Test incorrect parameters
    try {
        Rectangle invalidRect(-5, 10);
        invalidRect.calculateArea();
        cout << "Rectangle with invalid dimensions test failed: Exception not thrown!" << endl;
    }
    catch (logic_error e) {
        assert(string(e.what()) == "Invalid dimensions for Rectangle.");
    }

    // Test incorrect parameters
    try {
        Circle invalidCircle(0);
        invalidCircle.calculateArea();
        cout << "Circle with invalid radius test failed: Exception not thrown!" << endl;
    }
    catch (logic_error e) {
        assert(string(e.what()) == "Invalid radius for Circle.");
    }
    Rectangle rect2(2.5, 4.2);
    try {
        assert(abs(rect2.calculateArea() - 10.5) < 0.001);
    }
    catch (logic_error e) {
        cout << "Rectangle (2.5 x 4.2) test failed: " << e.what() << endl;
    }
    Circle circle2(1.5);
    assert(abs(circle2.calculateArea() - 7.068) < 0.001);


}

int main() {
    try {
        tests();
        cout << "All tests passed!" << endl;
    }
    catch (logic_error e) {
        cout << "Rectangle test failed: " << e.what() << endl;
    }
    catch (exception e) {
        cout << "Test failed: " << e.what() << endl;
    }
}
