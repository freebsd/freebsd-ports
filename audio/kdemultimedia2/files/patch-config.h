--- kscd/config.h.orig	Wed Aug 23 14:16:23 2000
+++ kscd/config.h	Fri Nov 24 20:11:35 2000
@@ -4,22 +4,8 @@
    config.h.std in the source directory of the kscd distribution
    and rename it to config.h .*/
 
-#ifdef __linux__
+#if defined(__FreeBSD__)
 
-#ifndef DEFAULT_CD_DEVICE
-  #define DEFAULT_CD_DEVICE   "/dev/cdrom"
-#endif
-
-#ifndef LINUX_SCSI_PASSTHROUGH
-  #define LINUX_SCSI_PASSTHROUGH 
-#endif
+#define DEFAULT_CD_DEVICE   "/dev/cdrom"
 
-#ifndef MIN_VOLUME
-  #define MIN_VOLUME 0
 #endif
-
-#ifndef MAX_VOLUME
-  #define MAX_VOLUME 255
-#endif
-
-#endif /* linux */
