--- vendor/f2fs-tools/lib/libf2fs.c	2024-08-29 19:46:57.000000000 +0200
+++ vendor/f2fs-tools/lib/libf2fs.c	2026-03-21 14:06:22.014748000 +0100
@@ -43,6 +43,9 @@
 #ifdef HAVE_LINUX_LIMITS_H
 #include <linux/limits.h>
 #endif
+#ifdef HAVE_LIMITS_H
+#include <limits.h>
+#endif
 
 /* SCSI command for standard inquiry*/
 #define MODELINQUIRY	0x12,0x00,0x00,0x00,0x4A,0x00
@@ -945,6 +948,13 @@
 #define BLKGETSIZE	DKIOCGETBLOCKCOUNT
 #define BLKSSZGET	DKIOCGETBLOCKCOUNT
 #endif /* APPLE_DARWIN */
+
+#if defined(__FreeBSD__)
+#include <sys/disk.h>
+#include <sys/ioctl.h>
+#define BLKGETSIZE64	DIOCGMEDIASIZE
+#define BLKSSZGET	DIOCGSECTORSIZE
+#endif /* __FreeBSD__ */
 
 #ifndef _WIN32
 static int open_check_fs(char *path, int flag)
