--- extras/ext4_utils/ext4_utils.cpp.orig	2019-08-13 02:10:50 UTC
+++ extras/ext4_utils/ext4_utils.cpp
@@ -32,8 +32,16 @@
 
 #if defined(__linux__)
 #include <linux/fs.h>
-#elif defined(__APPLE__) && defined(__MACH__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) \
+  || (defined(__APPLE__) && defined(__MACH__))
 #include <sys/disk.h>
+#elif defined(__sun)
+#include <sys/dkio.h>
+#elif defined(__Bitrig__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <sys/disklabel.h>
+#include <sys/dkio.h>
+#elif defined(__DragonFly__)
+#include <sys/diskslice.h>
 #endif
 
 int force = 0;
@@ -206,10 +214,24 @@ u64 get_block_device_size(int fd)
 	u64 size = 0;
 	int ret;
 
-#if defined(__linux__)
+#if defined(BLKGETSIZE64)
 	ret = ioctl(fd, BLKGETSIZE64, &size);
-#elif defined(__APPLE__) && defined(__MACH__)
+#elif defined(DKIOCGETBLOCKCOUNT)
 	ret = ioctl(fd, DKIOCGETBLOCKCOUNT, &size);
+#elif defined(DIOCGMEDIASIZE)
+	ret = ioctl(fd, DIOCGMEDIASIZE, &size);
+#elif defined(DKIOCGMEDIAINFO)
+	struct dk_minfo minfo;
+	ret = ioctl(fd, DKIOCGMEDIAINFO, &minfo);
+	size = minfo.dki_lbsize * minfo.dki_capacity;
+#elif defined(DIOCGDINFO)
+	struct disklabel dl;
+	ret = ioctl(fd, DIOCGDINFO, &dl);
+	size = dl.d_secsize * dl.d_nsectors * dl.d_ntracks * dl.d_ncylinders;
+#elif defined(DIOCGPART)
+	struct partinfo pi;
+	ret = ioctl(fd, DIOCGPART, &pi);
+	size = pi.media_size;
 #else
 	close(fd);
 	return 0;
