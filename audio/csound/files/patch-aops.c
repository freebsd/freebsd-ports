--- aops.c.orig	Thu Jan  4 03:48:26 2001
+++ aops.c	Thu Mar 15 06:26:31 2001
@@ -1,3 +1,4 @@
+#include <sys/time.h>
 #include "cs.h"		/*					AOPS.C	*/
 #include "aops.h"
 #include <math.h>
@@ -421,8 +422,6 @@
 #ifdef LINUX
 void rtclock(EVAL *p)
 {
-#include <sys/time.h>
-#include <unistd.h>
     struct timeval tv;
     struct timezone tz;
     gettimeofday(&tv, &tz);
