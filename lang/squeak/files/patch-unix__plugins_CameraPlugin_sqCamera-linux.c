--- unix/plugins/CameraPlugin/sqCamera-linux.c.orig	2012-07-31 06:59:01.000000000 +0900
+++ unix/plugins/CameraPlugin/sqCamera-linux.c	2012-09-24 14:44:26.000000000 +0900
@@ -45,8 +45,9 @@
 #include <sys/ioctl.h>
 #include <dlfcn.h>
 
-#include <asm/types.h>	  /* for videodev2.h */
-
+#ifdef __FreeBSD__
+#include <libv4l2.h>
+#endif
 #include <linux/videodev2.h>
 
 
@@ -176,12 +177,19 @@
 	int devNum;
 	camPtr cam;
 
+#ifndef __FreeBSD__
 	vd_open = open;
 	vd_close = close;
-	vd_dup = dup;
+	vd_mmap = mmap;
 	vd_ioctl = ioctl;
+#else
+	vd_open = v4l2_open;
+	vd_close = v4l2_close;
+	vd_mmap = v4l2_mmap;
+	vd_ioctl = v4l2_ioctl;
+#endif
+	vd_dup = dup;
 	vd_read = read;
-	vd_mmap = mmap;
 	vd_munmap = munmap;
 
 	/* Use libv4l2: use if available... */
