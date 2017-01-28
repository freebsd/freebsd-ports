--- src/db/DatabasePrint.cxx.orig	2017-01-03 19:47:53 UTC
+++ src/db/DatabasePrint.cxx
@@ -49,16 +49,14 @@ PrintDirectoryURI(Response &r, bool base
 		 ApplyBaseFlag(directory.GetPath(), base));
 }
 
-static bool
+static void
 PrintDirectoryBrief(Response &r, bool base, const LightDirectory &directory)
 {
 	if (!directory.IsRoot())
 		PrintDirectoryURI(r, base, directory);
-
-	return true;
 }
 
-static bool
+static void
 PrintDirectoryFull(Response &r, bool base, const LightDirectory &directory)
 {
 	if (!directory.IsRoot()) {
@@ -67,8 +65,6 @@ PrintDirectoryFull(Response &r, bool bas
 		if (directory.mtime > 0)
 			time_print(r, "Last-Modified", directory.mtime);
 	}
-
-	return true;
 }
 
 static void
@@ -96,7 +92,7 @@ print_playlist_in_directory(Response &r,
 			 directory->GetPath(), name_utf8);
 }
 
-static bool
+static void
 PrintSongBrief(Response &r, Partition &partition,
 	       bool base, const LightSong &song)
 {
@@ -106,11 +102,9 @@ PrintSongBrief(Response &r, Partition &p
 		/* this song file has an embedded CUE sheet */
 		print_playlist_in_directory(r, base,
 					    song.directory, song.uri);
-
-	return true;
 }
 
-static bool
+static void
 PrintSongFull(Response &r, Partition &partition,
 	      bool base, const LightSong &song)
 {
@@ -120,21 +114,18 @@ PrintSongFull(Response &r, Partition &pa
 		/* this song file has an embedded CUE sheet */
 		print_playlist_in_directory(r, base,
 					    song.directory, song.uri);
-
-	return true;
 }
 
-static bool
+static void
 PrintPlaylistBrief(Response &r, bool base,
 		   const PlaylistInfo &playlist,
 		   const LightDirectory &directory)
 {
 	print_playlist_in_directory(r, base,
 				    &directory, playlist.name.c_str());
-	return true;
 }
 
-static bool
+static void
 PrintPlaylistFull(Response &r, bool base,
 		  const PlaylistInfo &playlist,
 		  const LightDirectory &directory)
@@ -144,8 +135,6 @@ PrintPlaylistFull(Response &r, bool base
 
 	if (playlist.mtime > 0)
 		time_print(r, "Last-Modified", playlist.mtime);
-
-	return true;
 }
 
 void
@@ -191,15 +180,13 @@ db_selection_print(Response &r, Partitio
 			   0, std::numeric_limits<int>::max());
 }
 
-static bool
+static void
 PrintSongURIVisitor(Response &r, Partition &partition, const LightSong &song)
 {
 	song_print_uri(r, partition, song);
-
-	return true;
 }
 
-static bool
+static void
 PrintUniqueTag(Response &r, TagType tag_type,
 	       const Tag &tag)
 {
@@ -211,8 +198,6 @@ PrintUniqueTag(Response &r, TagType tag_
 		if (item.type != tag_type)
 			r.Format("%s: %s\n",
 				 tag_item_names[item.type], item.value);
-
-	return true;
 }
 
 void
