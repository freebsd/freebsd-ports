--- unix/plugins/CameraPlugin/sqCamera-linux.c.orig	2012-07-30 21:59:01 UTC
+++ unix/plugins/CameraPlugin/sqCamera-linux.c
@@ -45,8 +45,9 @@
 #include <sys/ioctl.h>
 #include <dlfcn.h>
 
-#include <asm/types.h>	  /* for videodev2.h */
-
+#ifdef __FreeBSD__
+#include <libv4l2.h>
+#endif
 #include <linux/videodev2.h>
 
 
@@ -176,12 +177,19 @@ libCon(void)
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
