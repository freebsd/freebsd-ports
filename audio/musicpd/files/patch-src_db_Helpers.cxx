--- src/db/Helpers.cxx.orig	2017-01-03 19:47:53 UTC
+++ src/db/Helpers.cxx
@@ -67,15 +67,13 @@ StatsVisitTag(DatabaseStats &stats, Stri
 	}
 }
 
-static bool
+static void
 StatsVisitSong(DatabaseStats &stats, StringSet &artists, StringSet &albums,
 	       const LightSong &song)
 {
 	++stats.song_count;
 
 	StatsVisitTag(stats, artists, albums, *song.tag);
-
-	return true;
 }
 
 DatabaseStats
