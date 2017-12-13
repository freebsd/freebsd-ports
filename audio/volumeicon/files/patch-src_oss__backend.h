--- src/oss_backend.h.orig	2015-03-02 22:54:36 UTC
+++ src/oss_backend.h
@@ -35,5 +35,7 @@ int oss_get_volume();
 gboolean oss_get_mute();
 const gchar * oss_get_channel();
 const GList * oss_get_channel_names();
+const gchar * oss_get_device();
+const GList * oss_get_device_names();
 
 #endif
