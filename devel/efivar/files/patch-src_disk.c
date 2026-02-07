--- src/disk.c.orig	2024-01-31 20:08:46 UTC
+++ src/disk.c
@@ -14,6 +14,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef __FreeBSD__
+#  include <sys/disk.h>
+#  undef LIST_HEAD
+#endif
 #include <sys/ioctl.h>
 #include <sys/mount.h>
 #include <sys/stat.h>
@@ -158,8 +162,18 @@ msdos_disk_get_partition_info (int fd, int write_signa
 	} else if (num == 0) {
 		/* Whole disk */
 		*start = 0;
+#if defined(__linux__)
 		ioctl(fd, BLKGETSIZE, &disk_size);
 		*size = disk_size;
+#elif defined(__FreeBSD__)
+		long sector_size=0;
+		ioctl(fd, DIOCGMEDIASIZE, &disk_size);
+		ioctl(fd, DIOCGSECTORSIZE, &sector_size);
+		*size = disk_size / sector_size;
+#else
+		efi_error("could not get disk size (not implemented on your OS)");
+		return -1;
+#endif
 	} else if (num >= 1 && num <= 4) {
 		/* Primary partition */
 		*start = mbr->partition[num-1].starting_lba;
