--- exif-gps.cpp.orig	2012-08-14 10:11:01 UTC
+++ exif-gps.cpp
@@ -40,10 +40,8 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
+#include <exiv2/exiv2.hpp>
 
-#include "exiv2/image.hpp"
-#include "exiv2/exif.hpp"
-
 #include "gpsstructure.h"
 #include "exif-gps.h"
 
@@ -87,7 +85,7 @@ char* ReadExifDate(char* File, int* IncludesGPS)
 {
 	// Open and read the file.
 	Exiv2::ExifData ExifRead;
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 
 	try {
 		Image = Exiv2::ImageFactory::open(File);
@@ -150,7 +148,7 @@ char* ReadExifData(char* File, double* Lat, double* Lo
 	// for display purposes. For the GUI version.
 	// Open and read the file.
 	Exiv2::ExifData ExifRead;
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 
 	try {
 		Image = Exiv2::ImageFactory::open(File);
@@ -268,7 +266,7 @@ char* ReadExifData(char* File, double* Lat, double* Lo
 
 		// Is the altitude below sea level? If so, negate the value.
 		GPSData = ExifRead["Exif.GPSInfo.GPSAltitudeRef"];
-		if (GPSData.count() >= 1 && GPSData.toLong() == 1)
+		if (GPSData.count() >= 1 && GPSData.toInt64() == 1)
 		{
 			// Negate the elevation.
 			*Elev = -*Elev;
@@ -289,7 +287,7 @@ char* ReadGPSTimestamp(char* File, char* DateStamp, ch
 	// for display purposes. For the GUI version.
 	// Open and read the file.
 	Exiv2::ExifData ExifRead;
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 
 	try {
 		Image = Exiv2::ImageFactory::open(File);
@@ -445,7 +443,7 @@ int WriteGPSData(char* File, struct GPSPoint* Point, c
 	struct utimbuf utb;
 	if (NoChangeMtime)
 		stat(File, &statbuf);
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 
 	try {
 		Image = Exiv2::ImageFactory::open(File);
@@ -473,7 +471,7 @@ int WriteGPSData(char* File, struct GPSPoint* Point, c
 	// Do all the easy constant ones first.
 	// GPSVersionID tag: standard says is should be four bytes: 02 00 00 00
 	//  (and, must be present).
-	Exiv2::Value::AutoPtr Value = Exiv2::Value::create(Exiv2::unsignedByte);
+	Exiv2::Value::UniquePtr Value = Exiv2::Value::create(Exiv2::unsignedByte);
 	Value->read("2 0 0 0");
 	ExifToWrite.add(Exiv2::ExifKey("Exif.GPSInfo.GPSVersionID"), Value.get());
 	// Datum: the datum of the measured data. If not given, we insert WGS-84.
@@ -660,7 +658,7 @@ int WriteFixedDatestamp(char* File, time_t Time)
 	struct utimbuf utb;
 	stat(File, &statbuf);
 
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 
 	try {
 		Image = Exiv2::ImageFactory::open(File);
@@ -699,7 +697,7 @@ int WriteFixedDatestamp(char* File, time_t Time)
 
 	char ScratchBuf[100];
 
-	Exiv2::Value::AutoPtr Value;
+	Exiv2::Value::UniquePtr Value;
 	Value = Exiv2::Value::create(Exiv2::signedRational);
 	snprintf(ScratchBuf, 100, "%d/1 %d/1 %d/1",
 			TimeStamp.tm_year + 1900,
@@ -737,7 +735,7 @@ int RemoveGPSExif(char* File, int NoChangeMtime)
 		stat(File, &statbuf);
 
 	// Open the file and start reading.
-	Exiv2::Image::AutoPtr Image;
+	Exiv2::Image::UniquePtr Image;
 	
 	try {
 		Image = Exiv2::ImageFactory::open(File);
