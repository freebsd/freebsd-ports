--- src/gpt.c.orig	2024-01-31 20:08:46 UTC
+++ src/gpt.c
@@ -16,6 +16,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)
+#  include <sys/disk.h>
+#  undef LIST_HEAD
+#endif
+#include <sys/ioctl.h>
 #include <sys/mount.h>
 #include <sys/param.h>
 #include <sys/stat.h>
@@ -60,6 +65,7 @@ is_pmbr_valid(legacy_mbr *mbr)
 	return (magic && found);
 }
 
+#if defined(__linux__)
 /**
  * kernel_has_blkgetsize64()
  *
@@ -92,6 +98,7 @@ kernel_has_blkgetsize64(void)
 		return 0;
 	return 1;
 }
+#endif
 
 /************************************************************
  * _get_num_sectors
@@ -114,6 +121,8 @@ _get_num_sectors(int filedes)
 	unsigned long sectors=0;
 	uint64_t bytes=0;
 	int rc;
+
+#if defined(__linux__)
 	if (kernel_has_blkgetsize64()) {
 		rc = ioctl(filedes, BLKGETSIZE64, &bytes);
 		if (!rc)
@@ -125,6 +134,19 @@ _get_num_sectors(int filedes)
 		return 0;
 
 	return sectors;
+#elif defined(__FreeBSD__)
+	rc = ioctl(filedes, DIOCGMEDIASIZE, &bytes);
+	if (rc == -1)
+		return 0;
+
+	rc = ioctl(filedes, DIOCGSECTORSIZE, &sectors);
+	if (rc == -1)
+		return 0;
+
+	return bytes / sectors;
+#else
+	return 0;
+#endif
 }
 
 /************************************************************
