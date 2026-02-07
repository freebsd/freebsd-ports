--- zbarcam/scan_video.c.orig	2021-02-13 09:54:57 UTC
+++ zbarcam/scan_video.c
@@ -32,7 +32,9 @@
 
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifndef __FreeBSD__
 #include <sys/sysmacros.h>
+#endif
 
 typedef void (cb_t) (void *userdata, const char *device);
 
