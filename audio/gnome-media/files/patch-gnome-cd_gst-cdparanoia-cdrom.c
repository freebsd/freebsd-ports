--- gnome-cd/gst-cdparanoia-cdrom.c.orig	Mon Apr  4 16:25:49 2005
+++ gnome-cd/gst-cdparanoia-cdrom.c	Mon Apr  4 16:26:14 2005
@@ -1224,6 +1224,16 @@
 		*status = NULL;
 		return FALSE;
 	}
+#else
+	if (ioctl (cdrom->fd, CDIOREADTOCHEADER, priv->tochdr) < 0) {
+		realstatus->cd = GNOME_CDROM_STATUS_NO_DISC;
+		realstatus->audio = GNOME_CDROM_AUDIO_NOTHING;
+		realstatus->track = -1;
+
+		gst_cdparanoia_cdrom_close (lcd);
+		return TRUE;
+	}
+	realstatus->cd = GNOME_CDROM_STATUS_OK;
 #endif
 
 	gst_cdparanoia_cdrom_close (lcd);
@@ -1421,15 +1431,18 @@
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
@@ -1441,6 +1454,7 @@
 	}
 
 	close (fd);
+#endif /* __FreeBSD__ */
 
 	return TRUE;
 }
