$FreeBSD$

--- aops.c.orig	Sun Jul 14 16:03:01 2002
+++ aops.c	Sun Jul 14 16:02:49 2002
@@ -1,3 +1,4 @@
+#include <sys/time.h>
 #include "cs.h"         /*                                      AOPS.C  */
 #include "aops.h"
 #include <math.h>
@@ -442,8 +443,6 @@ void ftsr(EVAL *p)              /**** ft
 }
 
 #ifdef LINUX
-#include <sys/time.h>
-#include <unistd.h>
 void rtclock(EVAL *p)
 {
     struct timeval tv;
