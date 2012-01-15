--- libgps.h.orig	2011-11-22 12:49:33.000000000 +0400
+++ libgps.h	2012-01-15 16:48:21.469612990 +0400
@@ -21,6 +21,7 @@
 #ifdef DBUS_EXPORT_ENABLE
     dbus,
 #endif /* DBUS_EXPORT_ENABLE */
+	dummy, /* so it compiles when all exports are disabled */
 };
 
 /* values to poke in the gps_fd member if we get it via something special */ 
