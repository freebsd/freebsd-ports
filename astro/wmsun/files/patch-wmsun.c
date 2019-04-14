--- wmsun.c.orig	2015-08-28 11:57:39 UTC
+++ wmsun.c
@@ -43,7 +43,6 @@
 /*
  *   Includes
  */
-#define _POSIX_C_SOURCE 1
 #include <X11/X.h>                     /* for ButtonPress, ButtonRelease, etc */
 #include <X11/Xlib.h>                  /* for XEvent, ConnectionNumber, etc */
 #include <math.h>                      /* for cos, sin */
@@ -106,7 +105,8 @@ int main(int argc, char *argv[]) {
     int			n;
     int 		Year, Month;
     int			DayOfMonth;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime;
+    long		date;
     double		UT, val, LTRise, LTSet, LocalHour, hour24();
     int			H, M;
     struct timeval	timeout;
