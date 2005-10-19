--- src/itdb_playlist.c.orig	Tue Oct 18 22:33:58 2005
+++ src/itdb_playlist.c	Tue Oct 18 22:34:23 2005
@@ -1184,8 +1184,9 @@
 /* Return playlist at position @num in @itdb */
 Itdb_Playlist *itdb_playlist_by_nr (Itdb_iTunesDB *itdb, guint32 num)
 {
+    Itdb_Playlist *pl;
     g_return_val_if_fail (itdb, NULL);
-    Itdb_Playlist *pl = g_list_nth_data (itdb->playlists, num);
+    pl = g_list_nth_data (itdb->playlists, num);
     g_return_val_if_fail (pl, NULL);
     return pl;
 }
