--- otherlibs/highgui/cvcap_v4l.cpp.orig	2006-09-27 10:40:03.000000000 +0900
+++ otherlibs/highgui/cvcap_v4l.cpp	2007-12-15 14:44:37.000000000 +0900
@@ -209,7 +209,6 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
