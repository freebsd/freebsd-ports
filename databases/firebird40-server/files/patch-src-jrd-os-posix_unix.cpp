--- src/jrd/os/posix/unix.cpp	2021-06-22 00:38:07.434896000 -0500
+++ src/jrd/os/posix/unix.cpp	2021-06-22 00:43:54.988645000 -0500
@@ -56,6 +56,13 @@
 #include <linux/fs.h>
 #endif
 
+#ifdef FREEBSD
+#include <sys/disk.h>
+#define BLKGETSIZE64 DIOCGMEDIASIZE
+#define BLKGETSIZE DIOCGMEDIASIZE
+#define BLKSSZGET DIOCGSECTORSIZE
+#endif
+
 #endif //SUPPORT_RAW_DEVICES
 
 #include "../jrd/jrd.h"
@@ -495,7 +502,7 @@
 // Looks like any OS needs own ioctl() to determine raw device size
 #undef HAS_RAW_SIZE
 
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 #ifdef BLKGETSIZE64
 		if (ioctl(file->fil_desc, BLKGETSIZE64, &length) != 0)
 #endif /*BLKGETSIZE64*/
