--- x11amp/main.c.orig	Wed Feb 25 19:38:20 2004
+++ x11amp/main.c	Wed Feb 25 19:38:52 2004
@@ -812,8 +812,8 @@
 	cleanup_ctrlsocket();
 	cleanup_skins();
 	playlist_stop_get_info_thread();
-	cleanup_plugins();
 	playlist_clear();
+	cleanup_plugins();
 	gtk_main_quit();
 }
 
