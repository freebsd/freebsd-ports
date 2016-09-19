--- src/stuff.c.orig	2015-01-19 21:17:42 UTC
+++ src/stuff.c
@@ -52,7 +52,7 @@ float decoy_table[ANGLE_1];	// not used
 float cos_table[ANGLE_1];
 float sin_table[ANGLE_1];
 
-inline int xpart (int angle, int length);
+int xpart (int angle, int length);
 
 void init_trig (void)
 {
@@ -67,12 +67,12 @@ void init_trig (void)
 
 }
 
-inline int xpart (int angle, int length)
+int xpart (int angle, int length)
 {
 	return (cos_table[angle & 1023] * length);
 }
 
-inline int ypart (int angle, int length)
+int ypart (int angle, int length)
 {
 	return (sin_table[angle & 1023] * length);
 }
