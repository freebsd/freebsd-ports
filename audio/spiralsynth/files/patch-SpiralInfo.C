--- SpiralInfo.C.orig	Mon Feb  9 13:26:01 2004
+++ SpiralInfo.C	Mon Feb  9 13:26:59 2004
@@ -22,8 +22,10 @@
 
 #include "SpiralSound/SpiralInfo.h"
 
-float RandFloat(float s=0.0f, float e=1.0f)
+float RandFloat(float s, float e)
 {
+	s=0.0f;
+	e=1.0f;
 	return s+((rand()%10000/10000.0)*(e-s));
 }
 
