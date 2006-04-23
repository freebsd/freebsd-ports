--- src/alutUtil.c.orig	Fri Mar 31 14:48:10 2006
+++ src/alutUtil.c	Fri Mar 31 14:48:22 2006
@@ -2,6 +2,7 @@
 
 #if HAVE_NANOSLEEP && HAVE_TIME_H
 #include <time.h>
+#include <sys/time.h>
 #include <errno.h>
 #elif HAVE_USLEEP && HAVE_UNISTD_H
 #include <unistd.h>
