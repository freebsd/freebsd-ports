--- libgphoto2_port/disk/disk.c.orig	Wed Apr 19 03:54:26 2006
+++ libgphoto2_port/disk/disk.c	Sun Nov 12 14:23:50 2006
@@ -175,7 +175,6 @@
 
 	libhal_free_string_array (volumes);
 	libhal_ctx_free (ctx);
-	dbus_connection_disconnect (dbus_connection);
 	dbus_connection_unref (dbus_connection);
 #else
 # ifdef HAVE_MNTENT_H
