--- src/main-window.c.orig	Thu Apr  8 17:49:42 2004
+++ src/main-window.c	Thu Apr  8 17:51:01 2004
@@ -2337,7 +2337,7 @@
 					GTK_STOCK_ADD, GTK_RESPONSE_ACCEPT,
 					NULL);
 
-  gtk_file_chooser_set_folder_mode (GTK_FILE_CHOOSER (dialog), TRUE);
+  gtk_file_chooser_set_action (GTK_FILE_CHOOSER (dialog), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
 
   start_dir = gconf_client_get_string (gconf_client,
 				       GCONF_PATH "/default_add_folder",
