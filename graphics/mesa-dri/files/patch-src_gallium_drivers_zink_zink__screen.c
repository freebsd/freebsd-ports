--- src/gallium/drivers/zink/zink_screen.c.orig	2023-12-01 14:18:25 UTC
+++ src/gallium/drivers/zink/zink_screen.c
@@ -55,7 +55,9 @@
 #include <xf86drm.h>
 #include <fcntl.h>
 #include <sys/stat.h>
+#if DETECT_OS_LINUX
 #include <sys/sysmacros.h>
+#endif
 #endif
 
 static int num_screens = 0;
