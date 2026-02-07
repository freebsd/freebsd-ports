--- src/stuff.h.orig	2015-01-19 20:19:08 UTC
+++ src/stuff.h
@@ -24,8 +24,8 @@ int grand (int number);
 int crandom (int number);
 int turn_towards_angle (int angle, int tangle, int turning);
 int turn_towards_xy (int x1, int y1, int x2, int y2, int angle, int turning);
-inline int xpart (int angle, int length);
-inline int ypart (int angle, int length);
+int xpart (int angle, int length);
+int ypart (int angle, int length);
 int pulsate (int speed, int amount, int county);
 int angle_difference (int a1, int a2);
 
