--- conv_fn.cc.orig	Thu Jun 30 15:10:32 2005
+++ conv_fn.cc	Thu Jun 30 15:11:11 2005
@@ -5,6 +5,7 @@

 #include <ctype.h>
 #include <math.h>
+#include <string.h>

 int GPStoLOCATOR(float gps_long, float gps_lat, char *locator) {
   /* gps_long and gps_lat are the longitutes (-180 to +180) and   */
