--- gnome-cd/gst-cdparanoia-cdrom.c.orig	Sat Mar 12 00:09:14 2005
+++ gnome-cd/gst-cdparanoia-cdrom.c	Sat Mar 12 00:19:15 2005
@@ -1443,15 +1443,18 @@
 		return FALSE;
 	}
 
+#if !defined(__FreeBSD__)
+	/* XXX: One cannot send CDIOCCAPABILITY to an atapicam CD-ROM
+	 * device.
+	 */
+
 	fd = open (device, O_RDONLY | O_NONBLOCK);
 	if (fd < 0) {
 		return FALSE;
 	}
 
 	/* Fire a harmless ioctl at the device. */
-#if defined(__FreeBSD__)
-	if (ioctl (fd, CDIOCCAPABILITY, 0) < 0) {
-#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 	if (ioctl (fd, CDIOCGETVOL, 0) < 0) {
 #else
 	if (ioctl (fd, CDROM_GET_CAPABILITY, 0) < 0) {
@@ -1463,6 +1466,7 @@
 	}
 
 	close (fd);
+#endif /* __FreeBSD__ */
 
 	return TRUE;
 }
