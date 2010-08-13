--- uhso.c.orig	2010-06-22 06:13:57.405352705 +0000
+++ uhso.c	2010-06-22 06:14:13.902069815 +0000
@@ -657,7 +657,8 @@
 static void
 uhso_cd_read_callback(struct usb_xfer *xfer, usb_error_t error)
 {
-	struct uhso_cd_softc *sc = usbd_xfer_softc(xfer);
+	struct uhso_cd_softc *sc;
+	sc = usbd_xfer_softc(xfer);
 
 	UHSO_DPRINTF(1, "sc=%p\n", sc);
 }
