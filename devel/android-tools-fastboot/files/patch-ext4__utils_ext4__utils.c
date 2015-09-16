--- ext4_utils/ext4_utils.c.orig	2012-12-18 23:27:26 UTC
+++ ext4_utils/ext4_utils.c
@@ -36,8 +36,16 @@
 
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
 
 #include "ext4.h"
@@ -383,10 +391,24 @@ static u64 get_block_device_size(int fd)
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
