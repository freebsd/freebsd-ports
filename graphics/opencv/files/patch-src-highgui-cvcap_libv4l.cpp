--- src/highgui/cvcap_libv4l.cpp.orig	2009-10-01 11:20:58.000000000 +1100
+++ src/highgui/cvcap_libv4l.cpp	2010-04-15 22:27:16.647412519 +1100
@@ -214,7 +214,6 @@
 #include <sys/mman.h>
 #include <string.h>
 #include <stdlib.h>
-#include <asm/types.h>          /* for videodev2.h */
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -466,8 +465,7 @@
 
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture)
 {
-
-  __u32 ctrl_id;
+  uint32_t ctrl_id;
 
   for (ctrl_id = V4L2_CID_BASE;
        ctrl_id < V4L2_CID_LASTP1;
