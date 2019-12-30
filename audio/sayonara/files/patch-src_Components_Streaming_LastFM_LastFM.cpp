--- src/Components/Streaming/LastFM/LastFM.cpp.orig	2019-12-30 14:17:48 UTC
+++ src/Components/Streaming/LastFM/LastFM.cpp
@@ -51,6 +51,7 @@
 #include <QUrl>
 
 #include <ctime>
+#include <random>
 
 namespace Algorithm=Util::Algorithm;
 
@@ -320,14 +321,14 @@ void Base::similar_artists_fetched(IdList artist_ids)
 
 	const MetaDataList& v_md = active_playlist->tracks();
 
-	std::random_shuffle(artist_ids.begin(), artist_ids.end());
+	std::shuffle(artist_ids.begin(), artist_ids.end(), std::default_random_engine());
 
 	for( auto it=artist_ids.begin(); it != artist_ids.end(); it++ )
 	{
 		MetaDataList artist_tracks;
 		lib_db->getAllTracksByArtist(IdList{*it}, artist_tracks);
 
-		std::random_shuffle(artist_tracks.begin(), artist_tracks.end());
+		std::shuffle(artist_tracks.begin(), artist_tracks.end(), std::default_random_engine());
 
 		// try all songs of artist
 		for(int rounds=0; rounds < artist_tracks.count(); rounds++)
