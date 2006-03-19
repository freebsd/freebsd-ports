--- draw.c.orig	Mon Jul 21 21:49:28 2003
+++ draw.c	Fri Mar 17 17:59:24 2006
@@ -605,7 +605,7 @@
 #define R270 (1.5*M_PI)
 #define R360 (2*M_PI)
 
-#include <sys/timeb.h>
+#include <sys/time.h>
 
 void draw_gain(int ie,Radpattern *rp)
 {
