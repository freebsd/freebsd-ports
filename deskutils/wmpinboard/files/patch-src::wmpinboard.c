--- wmpinboard.c.orig	Thu Apr 13 15:01:17 2000
+++ src/wmpinboard.c	Wed Apr 18 13:06:36 2001
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
+#include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/time.h>
 
@@ -1141,13 +1142,7 @@
 void
 timer(unsigned int intv)
 {
-#ifndef __GLIBC__
-  struct itimerval val = { { 0, intv }, { 0, intv } };
-
-  setitimer(ITIMER_REAL, &val, 0);
-#else
   ualarm(intv, intv);
-#endif
 }
 
 /*
