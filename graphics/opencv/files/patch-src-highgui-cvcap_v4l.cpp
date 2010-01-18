--- src/highgui/cvcap_v4l.cpp.orig	2009-11-25 03:13:51.305028046 +0000
+++ src/highgui/cvcap_v4l.cpp	2009-11-25 03:15:01.637453337 +0000
@@ -218,7 +218,6 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
