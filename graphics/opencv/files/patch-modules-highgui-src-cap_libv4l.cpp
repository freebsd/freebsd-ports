--- modules/highgui/src/cap_libv4l.cpp.orig	2011-06-21 15:24:06.000000000 +0200
+++ modules/highgui/src/cap_libv4l.cpp	2011-06-27 08:39:17.750223439 +0200
@@ -236,7 +236,6 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -568,7 +567,7 @@
 
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture) {
 
-  __u32 ctrl_id;
+  uint32_t ctrl_id;
   struct v4l2_control c;
   if (capture->v4l2_ctrl_ranges != NULL) {
     v4l2_free_ranges(capture);
