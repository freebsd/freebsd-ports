--- cdrombsd.h.orig	Sat Aug 18 14:09:10 2001
+++ cdrombsd.h	Thu Mar  4 09:55:32 2004
@@ -5,15 +5,17 @@
 #ifndef CDROMBSD_H
 #define CDROMBSD_H
 #include <sys/param.h>
+#include <sys/cdrio.h>
+#ifndef CD_FRAMESIZE_RAW
+#define CD_FRAMESIZE_RAW 2352
+#endif
 /*\
 |*| FreeBSD (?) specific code
 \*/
 
-#define GET_LBA(entry) ((entry.addr_type == CD_LBA_FORMAT) ? \
-				ntohl(entry.addr.lba) : \
-					((entry.addr.msf.minute * 60 + \
-					entry.addr.msf.second) * 75 + \
-					entry.addr.msf.frame))
+#define GET_LBA(entry) ((entry.addr.msf.minute * 60 \
+			+ entry.addr.msf.second) * 75 \
+			+ entry.addr.msf.frame)
 
 
 /*\
@@ -26,16 +28,14 @@
 	int fd;
 	fd = open(device, O_RDONLY|O_NONBLOCK);
 	if (fd < 0) return -1;
-#ifdef CDROM_SELECT_SPEED
 	if (!(*flags & FLAG_FAIL_SPD) &&
-	    (ioctl(fd, CDROM_SELECT_SPEED, cd_cfg.cdrom_speed) < 0)) {
+	    (ioctl(fd, CDRIOCREADSPEED, &cd_cfg.cdrom_speed) < 0)) {
 		if (errno == ENOTTY) {
 			close(fd);
 			return -1;
 		}
 		*flags |= FLAG_FAIL_SPD;
 	}
-#endif
 	return fd;
 }
 
@@ -84,6 +84,16 @@
 |*|  from device cdfd, at position lba
 |*|  Return number of successfully read frames, -1 on error.
 \*/
+#if __FreeBSD_version >= 501106
+static int
+cdrom_read_audio(int cdfd, int lba, char *buf, int btw)
+{
+	int bsize = CD_FRAMESIZE_RAW;
+	if (ioctl(cdfd, CDRIOCSETBLOCKSIZE, &bsize) == -1) return -errno;
+	if (pread(cdfd, buf, btw*bsize, (lba - 150)*bsize) != btw*bsize) return 0;
+	return btw; 
+}
+#else // 4-STABLE
 static int
 cdrom_read_audio(int cdfd, int lba, char *buf, int btw)
 {
@@ -101,6 +111,7 @@
 	} while (--rtr >= 0);
 	return -1;
 }
+#endif // FreeBSD_version
 
 /*\ Play audio from lba address from, to lba address to
 |*|  return -1 on failure
