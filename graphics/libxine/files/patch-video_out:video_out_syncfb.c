--- src/video_out/video_out_syncfb.c.orig	Thu May 16 23:32:35 2002
+++ src/video_out/video_out_syncfb.c	Thu May 16 23:32:57 2002
@@ -39,6 +39,7 @@
 #include <sys/ioccom.h>
 #endif
 
+#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <sys/shm.h>
