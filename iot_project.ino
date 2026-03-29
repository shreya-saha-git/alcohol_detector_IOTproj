// Define pins
const int alcoholSensorPin = A0; // MQ-3 Analog output
const int relayPin = 8;          // Relay module
const int buzzerPin = 9;         // Buzzer
const int redLedPin = 10;        // Red LED (alert)
const int greenLedPin = 11;      // Green LED (safe)

// Alcohol threshold (calibrate based on your sensor readings)
const int alcoholThreshold = 400;

void setup() {
  pinMode(alcoholSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  digitalWrite(relayPin, LOW); // Ensure the relay is off initially
  Serial.begin(9600);          // For debugging
}

void loop() {
  int sensorValue = analogRead(alcoholSensorPin); // Read alcohol sensor value
  
  // Print sensor value to Serial Monitor for calibration
  Serial.print("Alcohol Level: ");
  Serial.println(sensorValue);

  if (sensorValue > alcoholThreshold) {
    // Alcohol detected
    digitalWrite(relayPin, LOW);    // Disable ignition
    digitalWrite(buzzerPin, HIGH);  // Activate buzzer
    digitalWrite(redLedPin, HIGH);  // Turn on red LED
    digitalWrite(greenLedPin, LOW); // Turn off green LED
    Serial.println("Alcohol detected! Car won't start.");
  } else {
    // No alcohol detected
    digitalWrite(relayPin, HIGH);   // Enable ignition
    digitalWrite(buzzerPin, LOW);   // Deactivate buzzer
    digitalWrite(redLedPin, LOW);   // Turn off red LED
    digitalWrite(greenLedPin, HIGH);// Turn on green LED
    Serial.println("No alcohol detected. Car can start.");
  }

  delay(500); // Delay for stability
}

