--- src/db/DatabasePlaylist.cxx.orig	2017-01-03 19:47:53 UTC
+++ src/db/DatabasePlaylist.cxx
@@ -27,13 +27,12 @@
 
 #include <functional>
 
-static bool
+static void
 AddSong(const Storage &storage, const char *playlist_path_utf8,
 	const LightSong &song)
 {
 	spl_append_song(playlist_path_utf8,
 			DatabaseDetachSong(storage, song));
-	return true;
 }
 
 void
