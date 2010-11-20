--- gsettings/dconfsettingsbackend.c.orig	2010-11-03 00:18:46.000000000 +0100
+++ gsettings/dconfsettingsbackend.c	2010-11-03 00:21:03.000000000 +0100
@@ -155,6 +155,7 @@ dconf_settings_backend_remove_outstandin
                                       g_dbus_message_get_sender (message),
                                       g_dbus_message_get_body (message),
                                       anti_expose, NULL);
+        g_slice_free (Outstanding, tmp);
 
         found = TRUE;
         break;
@@ -457,6 +458,7 @@ dconf_settings_backend_write_tree (GSett
                                    gpointer          origin_tag)
 {
   DConfSettingsBackend *dcsb = (DConfSettingsBackend *) backend;
+  gboolean success = FALSE;
   volatile guint32 *serial;
   DConfEngineMessage dcem;
   GDBusConnection *bus;
@@ -478,15 +480,11 @@ dconf_settings_backend_write_tree (GSett
 
           g_settings_backend_keys_changed (backend, prefix, keys, origin_tag);
 
-          return TRUE;
+          success = TRUE;
         }
     }
 
-  g_free (prefix);
-  g_free (values);
-  g_free (keys);
-
-  return FALSE;
+  return success;
 }
 
 static void
