--- ./modules/highgui/src/cap_v4l.cpp.orig	2013-10-23 23:54:06.000000000 -0400
+++ ./modules/highgui/src/cap_v4l.cpp	2013-10-23 23:55:25.000000000 -0400
@@ -232,7 +232,6 @@
 #include <sys/ioctl.h>
 
 #ifdef HAVE_CAMV4L2
-#include <asm/types.h>          /* for videodev2.h */
 #include <linux/videodev2.h>
 #endif
 
@@ -663,7 +662,7 @@
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture)
 {
 
-  __u32 ctrl_id;
+  uint32_t ctrl_id;
 
   for (ctrl_id = V4L2_CID_BASE;
        ctrl_id < V4L2_CID_LASTP1;
