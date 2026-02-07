--- SpiralSound/SpiralInfo.C.orig	Wed Nov 22 13:05:47 2006
+++ SpiralSound/SpiralInfo.C	Wed Nov 22 13:06:04 2006
@@ -22,7 +22,7 @@
 
 #include "SpiralInfo.h"
 
-float RandFloat(float s=0.0f, float e=1.0f)
+float RandFloat(float s, float e)
 {
 	return s+((rand()%10000/10000.0)*(e-s));
 }
