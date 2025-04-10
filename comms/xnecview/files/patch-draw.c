--- draw.c.orig	2020-01-11 15:14:27 UTC
+++ draw.c
@@ -615,7 +615,7 @@ void draw_gain_phi(int j,Radpattern *rp)
 #define R270 (1.5*M_PI)
 #define R360 (2*M_PI)
 
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 void draw_gain(int ie,Radpattern *rp)
 {
