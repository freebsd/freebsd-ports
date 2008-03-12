--- CalcEphem.c.orig	2001-11-07 01:34:50.000000000 +0100
+++ CalcEphem.c	2008-03-12 13:14:01.000000000 +0100
@@ -8,6 +8,7 @@
 #include <config.h>
 #endif
 
+#include <string.h>
 #include <time.h>
 #include <X11/X.h>
 
@@ -239,7 +240,7 @@
     double UTRise, UTSet;
     double LTRise, LTSet;
     struct tm *LocalTime;
-    long CurrentGMTTime;
+    time_t CurrentGMTTime;
     double LocalHour, TimeZone;
 
     SinH0 = sin( -50.0/60.0 * RadPerDeg );
