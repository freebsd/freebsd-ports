--- gnect/src/prefs.c.orig	Sun May 25 14:21:05 2003
+++ gnect/src/prefs.c	Sun May 25 14:21:15 2003
@@ -264,40 +264,6 @@
 
 
 
-static void 
-sanity_check(void)
-{
-  gchar *tileset;
-  GError *error = NULL;
-  
-  tileset = gconf_client_get_string (gnect_gconf_client,
-                                     "/apps/gnect/theme", &error);
-  if (error) {
-    GtkWidget *dialog;
-    dialog = gtk_message_dialog_new (NULL,
-                                     0,
-                                     GTK_MESSAGE_ERROR,
-                                     GTK_BUTTONS_CLOSE,
-                                     _("There was an error accessing GConf: %s"),
-                                     error->message);
-    gtk_window_set_resizable (GTK_WINDOW (dialog), FALSE);
-    gtk_dialog_run(GTK_DIALOG(dialog));
-    exit(1);
-  } else if (!tileset) {
-    GtkWidget *dialog;
-    dialog = gtk_message_dialog_new (NULL,
-                                     0,
-                                     GTK_MESSAGE_ERROR,
-                                     GTK_BUTTONS_CLOSE,
-                                     _("The default configuration values could not be retrieved correctly. Please check your GConf configuration, specifically that the schemas are installed correctly"));
-    gtk_window_set_resizable (GTK_WINDOW (dialog), FALSE);
-    gtk_dialog_run(GTK_DIALOG(dialog));
-    exit(1);
-  } else {
-    g_free (tileset);
-  }
-}
-
 void
 prefs_init (gint argc, gchar **argv)
 {
@@ -313,7 +279,6 @@
 
         gconf_init (argc, argv, NULL);
         gnect_gconf_client = gconf_client_get_default ();
-        sanity_check();
         gconf_client_add_dir (gnect_gconf_client, "/apps/gnect",
                               GCONF_CLIENT_PRELOAD_NONE, NULL);
 
