--- src/db/Count.cxx.orig	2017-01-03 19:47:53 UTC
+++ src/db/Count.cxx
@@ -62,7 +62,7 @@ Print(Response &r, TagType group, const 
 	}
 }
 
-static bool
+static void
 stats_visitor_song(SearchStats &stats, const LightSong &song)
 {
 	stats.n_songs++;
@@ -70,8 +70,6 @@ stats_visitor_song(SearchStats &stats, c
 	const auto duration = song.GetDuration();
 	if (!duration.IsNegative())
 		stats.total_duration += duration;
-
-	return true;
 }
 
 static bool
@@ -94,7 +92,7 @@ CollectGroupCounts(TagCountMap &map, Tag
 	return found;
 }
 
-static bool
+static void
 GroupCountVisitor(TagCountMap &map, TagType group, const LightSong &song)
 {
 	assert(song.tag != nullptr);
@@ -103,8 +101,6 @@ GroupCountVisitor(TagCountMap &map, TagT
 	if (!CollectGroupCounts(map, group, tag) && group == TAG_ALBUM_ARTIST)
 		/* fall back to "Artist" if no "AlbumArtist" was found */
 		CollectGroupCounts(map, TAG_ARTIST, tag);
-
-	return true;
 }
 
 void
