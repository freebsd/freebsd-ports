--- src/song-browser.c.orig	Sat Jul 10 17:12:59 2004
+++ src/song-browser.c	Sun Jul 25 17:39:25 2004
@@ -626,8 +626,9 @@
 		return;
 	if (add_list != NULL)
 	{
+		GList *song;
 		mpd_sendCommandListBegin (info.connection);
-		GList *song = g_list_first (add_list);
+		song = g_list_first (add_list);
 		do
 		{
 			mpd_sendAddCommand (info.connection, song->data);
