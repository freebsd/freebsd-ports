--- src/sj-main.c.orig	Wed Jan  7 20:38:00 2004
+++ src/sj-main.c	Thu Jan 22 14:22:54 2004
@@ -535,9 +535,10 @@
  */
 void device_changed_cb (GConfClient *client, guint cnxn_id, GConfEntry *entry, gpointer user_data)
 {
-  g_assert (strcmp (entry->key, GCONF_DEVICE) == 0);
   gboolean ignore_no_media = GPOINTER_TO_INT (user_data);
 
+  g_assert (strcmp (entry->key, GCONF_DEVICE) == 0);
+
   if (entry->value == NULL) {
     device = prefs_get_default_device();
     if (device == NULL) {
@@ -833,7 +834,7 @@
 void on_contents_activate(GtkWidget *button, gpointer user_data) {
   GError *error = NULL;
 
-  gnome_help_display ("sound-juicer", NULL, &error);
+  gnome_help_display ("sound-juicer.xml", NULL, &error);
   if (error) {
     GtkWidget *dialog;
 
@@ -870,6 +871,7 @@
                       VERSION, LIBGNOMEUI_MODULE,
                       argc, argv,
                       GNOME_PARAM_POPT_TABLE, options,
+                      GNOME_PARAM_APP_DATADIR, DATADIR,
                       NULL);
   g_set_application_name (_("Sound Juicer"));
 
