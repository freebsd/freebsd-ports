--- src/Player.cpp.orig	Sun Aug 13 14:36:55 2006
+++ src/Player.cpp	Thu Aug 24 21:22:42 2006
@@ -31,6 +31,10 @@
 
 // member functions
 
+#ifndef INFINITY
+#define INFINITY MAXFLOAT
+#endif
+
 Player::Player(ToyCar& inCar, list<Tuple> *path, int inPlayerNumber)
 	: car(inCar), lapFlag(0), laps(-1), curLap(-1e-1), prevLap(-1e-1), revolutions(-1), bestLapTime(INFINITY), courseTime(0.0),
 	  pathEnd(path->end()), pathClosestPerp(INFINITY), pathSize(path->size()), playerNumber(inPlayerNumber)
