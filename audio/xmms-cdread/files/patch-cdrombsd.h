--- cdrombsd.h.orig	Sat Aug 18 15:09:10 2001
+++ cdrombsd.h	Thu Nov 20 19:24:05 2003
@@ -5,15 +5,19 @@
 #ifndef CDROMBSD_H
 #define CDROMBSD_H
 #include <sys/param.h>
+#if __FreeBSD_version >= 501106
+#include <sys/cdrio.h>
+#ifndef CD_FRAMESIZE_RAW
+#define CD_FRAMESIZE_RAW 2352
+#endif
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
@@ -84,6 +88,16 @@
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
@@ -101,6 +115,7 @@
 	} while (--rtr >= 0);
 	return -1;
 }
+#endif // FreeBSD_version
 
 /*\ Play audio from lba address from, to lba address to
 |*|  return -1 on failure
