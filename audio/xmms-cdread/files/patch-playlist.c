--- playlist.c.orig	Sun Jun  3 18:58:51 2001
+++ playlist.c	Mon Sep  8 19:46:59 2003
@@ -161,7 +161,6 @@
 	pthread_mutex_unlock(&playlist_mutex);
 	
 	playlistwin_update_list();
-	if (regen_shuffle) playlist_generate_shuffle_list();
 	if (set_info_text) mainwin_set_info_text();
 	if (restart_playing)
 	{
