--- src/sj-main.c.orig	Tue Jun 15 19:45:05 2004
+++ src/sj-main.c	Tue Jun 15 19:46:13 2004
@@ -535,8 +535,9 @@
  */
 void device_changed_cb (GConfClient *client, guint cnxn_id, GConfEntry *entry, gpointer user_data)
 {
-  g_assert (strcmp (entry->key, GCONF_DEVICE) == 0);
   gboolean ignore_no_media = GPOINTER_TO_INT (user_data);
+
+  g_assert (strcmp (entry->key, GCONF_DEVICE) == 0);
 
   if (entry->value == NULL
 		  || !cd_drive_exists (gconf_value_get_string (entry->value))) {
