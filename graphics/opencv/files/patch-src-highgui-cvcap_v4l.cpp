--- src/highgui/cvcap_v4l.cpp.orig	2009-11-25 03:13:51.305028046 +0000
+++ src/highgui/cvcap_v4l.cpp	2009-11-25 03:15:01.637453337 +0000
@@ -218,7 +218,6 @@
 
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -646,8 +646,7 @@

 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture)
 {
-
-  __u32 ctrl_id;
+   uint32_t ctrl_id;

   for (ctrl_id = V4L2_CID_BASE;
        ctrl_id < V4L2_CID_LASTP1;
