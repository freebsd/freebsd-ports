--- plat_freebsd.c.orig	Mon Feb 20 17:29:55 1995
+++ plat_freebsd.c	Tue Oct 13 03:24:22 1998
@@ -5,6 +5,9 @@
  *
  * Todd Pfaff, 3/20/94
  *
+ * 11/26/95: Modified to work under FreeBSD 2.x
+ *           by Donald Burr <d_burr@ix.netcom.com>
+ *
  */
 static char *ident = "@(#)plat_freebsd.c	1.2 2/20/95";
 
@@ -22,21 +25,17 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/cdio.h>
-#include <sys/scsiio.h>
 #ifdef __NetBSD__
 #define MSF_MINUTES 1
 #define MSF_SECONDS 2
 #define MSF_FRAMES 3
 #include "/sys/scsi/scsi_all.h"
 #include "/sys/scsi/scsi_cd.h"
-#else
-#include <scsi/scsi_all.h>
-#include <scsi/scsi_cd.h>
 #endif
 
 #include "struct.h"
 
-#define DEFAULT_CD_DEVICE       "/dev/rcd0d"
+#define DEFAULT_CD_DEVICE       "/dev/rcd0c"
 
 void *malloc();
 
@@ -163,7 +162,7 @@
 	}
 
 	if (ioctl(d->fd, CDIOCREADSUBCHANNEL, &sc)) {
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 	    /* we need to release the device so the kernel will notice
 	       reloaded media */
 	    (void) close(d->fd);
@@ -261,6 +260,9 @@
 
 	bzero((char *)&vol, sizeof(vol));
 
+#define LEFT_PORT 0
+#define RIGHT_PORT 1
+
 	vol.vol[LEFT_PORT] = left;
 	vol.vol[RIGHT_PORT] = right;
 
@@ -345,12 +347,12 @@
 	if (fstatfs(stbuf.st_rdev, &buf) == 0)
 		return (-3);
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 	rval = ioctl(d->fd, CDIOCALLOW);
 	if (rval == 0)
 #endif
 	    rval = ioctl(d->fd, CDIOCEJECT);
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 	if (rval == 0)
 	    rval = ioctl(d->fd, CDIOCPREVENT);
 #endif
