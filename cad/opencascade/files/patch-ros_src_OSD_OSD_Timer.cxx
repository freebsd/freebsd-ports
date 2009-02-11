--- ./ros/src/OSD/OSD_Timer.cxx.orig	2003-11-17 19:44:23.000000000 +0100
+++ ./ros/src/OSD/OSD_Timer.cxx	2009-02-10 21:58:31.000000000 +0100
@@ -26,6 +26,8 @@
 # include <sys/time.h>
 #endif
 
+#include <stdlib.h>
+
 static struct timezone *tz=(struct timezone*) malloc(sizeof(struct timezone));
 
 //=======================================================================
