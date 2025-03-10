--- wmsun.c.orig	2024-10-17 21:51:08 UTC
+++ wmsun.c
@@ -43,7 +43,7 @@
 /*
  *   Includes
  */
-#define _POSIX_C_SOURCE 1
+#define _POSIX_C_SOURCE 200112L
 #include <X11/X.h>                     /* for ButtonPress, ButtonRelease, etc */
 #include <X11/Xlib.h>                  /* for XEvent, ConnectionNumber, etc */
 #include <math.h>                      /* for cos, sin */
@@ -105,7 +105,7 @@
     int			n;
     int 		Year, Month;
     int			DayOfMonth;
-    long		CurrentLocalTime, CurrentGMTTime, date;
+    time_t		CurrentLocalTime, CurrentGMTTime, date;
     double		UT, val, LTRise, LTSet, LocalHour, hour24();
     int			H, M;
     struct timeval	timeout;
