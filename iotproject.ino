// Interfacing the Pulse sensior
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Lieutenant S"; //Your Network SSID
const char* password = "syaoran13"; //Your Network Password

int val;
int PulseSensorpin = A0; //Pulse Sensor Pin Connected at A0 Pin
WiFiClient client;

unsigned long myChannelNumber = 1854864 ; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "LP1WLKXFXCQKKF2K"; //Your Write API Key

void setup()
{
 Serial.begin(9600);
 delay(10);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(PulseSensorpin); //Read Analog values and Store in val variable
  Serial.println("Pulse Sensorvalue=  "); // Start Printing on Pulse sensor value on LCD
  Serial.println(val); // Start Printing on Pulse sensor value on LCD
  delay(100);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
}
