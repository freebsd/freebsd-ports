--- hot-babe.c.orig	Tue Nov 16 22:52:44 2004
+++ hot-babe.c	Wed Nov 24 12:15:34 2004
@@ -20,9 +20,11 @@
 #include <stdlib.h>
 #include <string.h>
 #ifdef __FreeBSD__
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
+#include <sys/dkstat.h>
 #endif
 
 /* x11 includes */
