--- widgets/rb-song-info.c.orig	Mon Apr 17 03:10:40 2006
+++ widgets/rb-song-info.c	Mon Apr 17 03:11:42 2006
@@ -750,7 +750,7 @@ rb_song_info_populate_dialog (RBSongInfo
 {
 	const char *text;
 	char *tmp;
-	ulong num;
+	gulong num;
 	
 	g_assert (song_info->priv->current_entry);
 
@@ -1063,7 +1063,7 @@ rb_song_info_update_rating (RBSongInfo *
 static void
 rb_song_info_update_year (RBSongInfo *song_info)
 {
-	ulong year;
+	gulong year;
 	char *text;
 
 	year = rhythmdb_entry_get_ulong (song_info->priv->current_entry, RHYTHMDB_PROP_YEAR);
@@ -1183,7 +1183,7 @@ rb_song_info_sync_entries_multiple (RBSo
 		g_value_set_ulong (&val, discn);
 
 		for (tem = dialog->priv->selected_entries; tem; tem = tem->next) {
-			ulong entry_disc_num;
+			gulong entry_disc_num;
 			
 			entry = (RhythmDBEntry *)tem->data;
 			entry_disc_num = rhythmdb_entry_get_ulong (entry, RHYTHMDB_PROP_DISC_NUMBER);
