
$FreeBSD$

--- CalcEphem.c.orig	Thu Aug 15 15:34:37 2002
+++ CalcEphem.c	Thu Aug 15 15:35:00 2002
@@ -239,7 +239,7 @@
     double UTRise, UTSet;
     double LTRise, LTSet;
     struct tm *LocalTime;
-    long CurrentGMTTime;
+    time_t CurrentGMTTime;
     double LocalHour, TimeZone;
 
     SinH0 = sin( -50.0/60.0 * RadPerDeg );
