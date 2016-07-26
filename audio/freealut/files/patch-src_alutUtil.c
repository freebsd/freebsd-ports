--- src/alutUtil.c.orig	2006-05-08 09:28:07 UTC
+++ src/alutUtil.c
@@ -2,6 +2,7 @@
 
 #if HAVE_NANOSLEEP && HAVE_TIME_H
 #include <time.h>
+#include <sys/time.h>
 #include <errno.h>
 #elif HAVE_USLEEP && HAVE_UNISTD_H
 #include <unistd.h>
