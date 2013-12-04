--- ./modules/highgui/src/cap_libv4l.cpp.orig	2013-07-10 07:49:00.000000000 -0400
+++ ./modules/highgui/src/cap_libv4l.cpp	2013-10-23 23:52:32.000000000 -0400
@@ -237,7 +237,6 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -574,7 +573,7 @@
 
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture) {
 
-  __u32 ctrl_id;
+  uint32_t ctrl_id;
   struct v4l2_control c;
   if (capture->v4l2_ctrl_ranges != NULL) {
     v4l2_free_ranges(capture);
