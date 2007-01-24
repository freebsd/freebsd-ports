--- utc_gst.c.orig	Sun Jan 21 21:13:45 2007
+++ utc_gst.c	Sun Jan 21 21:14:05 2007
@@ -1,5 +1,7 @@
 #include "astro.h"
 
+static double tnaught(double mjd);
+
 /* given a modified julian date, mjd, and a universally coordinated time, utc,
  * return greenwich mean siderial time, *gst.
  */
