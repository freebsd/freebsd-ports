$FreeBSD$

--- aops.c.orig	Sun Jul 14 16:03:01 2002
+++ aops.c	Sun Jul 14 16:02:49 2002
@@ -1,3 +1,4 @@
+#include <sys/time.h>
 #include "cs.h"         /*                                      AOPS.C  */
 #include "aops.h"
 #include <math.h>
@@ -442,8 +443,6 @@ void ftsr(EVAL *p)              /**** ft
 #ifdef LINUX
 void rtclock(EVAL *p)
 {
-#include <sys/time.h>
-#include <unistd.h>
     struct timeval tv;
     struct timezone tz;
     gettimeofday(&tv, &tz);
