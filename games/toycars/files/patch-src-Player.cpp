--- src/Player.cpp.orig	Sat Nov 26 01:04:36 2005
+++ src/Player.cpp	Mon Dec 19 11:26:04 2005
@@ -33,6 +33,10 @@
 
 // member functions
 
+#ifndef INFINITY
+#define INFINITY MAXFLOAT
+#endif
+
 Player::Player(ToyCar& inCar)
 	: car(inCar), lapFlag(-1), laps(0), curLap(0.0), prevLap(0.0), bestLapTime(INFINITY), courseTime(0.0)
 {
