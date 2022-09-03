--- common/xfce-notify-log.c.orig	2022-09-02 07:22:08 UTC
+++ common/xfce-notify-log.c
@@ -149,7 +149,9 @@ notify_get_from_desktop_file (const gchar *desktop_fil
 
             match = matches[0];
             appinfo = g_desktop_app_info_new (match[0]);
-            value = notify_read_from_desktop_file (g_desktop_app_info_get_filename (appinfo), key);
+            if (appinfo != NULL) {
+                value = notify_read_from_desktop_file (g_desktop_app_info_get_filename (appinfo), key);
+            }
 
             for (gchar ***p = matches; *p != NULL; p++)
                 g_strfreev (*p);
