--- gnome-cd/freebsd-cdrom.c.orig	Tue Jun 11 15:43:37 2002
+++ gnome-cd/freebsd-cdrom.c	Tue Jun 11 15:43:55 2002
@@ -75,7 +75,7 @@
 static void
 freebsd_cdrom_finalize (GObject *object)
 {
-	FreeBSDCDrom *cdrom = (FreeBSDCDrom *) object;
+	FreeBSDCDRom *cdrom = (FreeBSDCDRom *) object;
 
 	g_free (cdrom->priv);
 
