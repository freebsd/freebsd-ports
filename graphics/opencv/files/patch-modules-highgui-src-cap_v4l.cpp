--- modules/highgui/src/cap_v4l.cpp.orig	2011-06-21 15:24:06.000000000 +0200
+++ modules/highgui/src/cap_v4l.cpp	2011-06-27 08:38:16.221682985 +0200
@@ -218,7 +218,6 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -649,8 +648,7 @@
 
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture)
 {
-
-  __u32 ctrl_id;
+   uint32_t ctrl_id;
 
   for (ctrl_id = V4L2_CID_BASE;
        ctrl_id < V4L2_CID_LASTP1;
