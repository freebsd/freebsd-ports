--- include/my_global.h.orig	2014-11-19 12:34:01.000000000 +0100
+++ include/my_global.h	2014-11-19 12:34:39.000000000 +0100
@@ -333,9 +333,6 @@
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
-#ifdef HAVE_SYS_TIMEB_H
-#include <sys/timeb.h>				/* Avoid warnings on SCO */
-#endif
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
 # include <time.h>
