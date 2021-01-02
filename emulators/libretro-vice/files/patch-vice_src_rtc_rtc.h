--- vice/src/rtc/rtc.h.orig	2020-12-18 10:39:47 UTC
+++ vice/src/rtc/rtc.h
@@ -28,10 +28,7 @@
 #define VICE_RTC_H
 
 #include "types.h"
-
-#ifdef HAVE_TIME_T_IN_TIME_H
 #include <time.h>
-#endif
 
 #ifdef HAVE_TIME_T_IN_TYPES_H
 #include <sys/types.h>
