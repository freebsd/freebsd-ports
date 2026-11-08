--- modules/videoio/src/cap_v4l.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -227,16 +227,18 @@ make & enjoy!
 #include <poll.h>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
 #ifdef HAVE_VIDEOIO
-// NetBSD compatibility layer with V4L2
+// NetBSD and FreeBSD compatibility layer with V4L2
 #include <sys/videoio.h>
 #endif
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 typedef uint32_t __u32;
 #endif
 
