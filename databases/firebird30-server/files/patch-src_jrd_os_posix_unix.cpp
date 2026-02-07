--- src/jrd/os/posix/unix.cpp.orig	2022-06-07 08:18:52 UTC
+++ src/jrd/os/posix/unix.cpp
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
@@ -496,7 +503,7 @@ ULONG PIO_get_number_of_pages(const jrd_file* file, co
 // Looks like any OS needs own ioctl() to determine raw device size
 #undef HAS_RAW_SIZE
 
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 #ifdef BLKGETSIZE64
 		if (ioctl(file->fil_desc, BLKGETSIZE64, &length) != 0)
 #endif /*BLKGETSIZE64*/
