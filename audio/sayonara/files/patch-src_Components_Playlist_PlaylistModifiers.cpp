--- src/Components/Playlist/PlaylistModifiers.cpp.orig	2024-06-04 19:25:08 UTC
+++ src/Components/Playlist/PlaylistModifiers.cpp
@@ -179,7 +179,7 @@ namespace Playlist
 		const auto& tracks = playlist.tracks();
 		const auto durationMs =
 			std::accumulate(tracks.begin(), tracks.end(), 0, [](const auto timeMs, const auto& track) {
-				return timeMs + std::max(0L, track.durationMs());
+				return timeMs + std::max(MilliSeconds(0), track.durationMs());
 			});
 
 		return durationMs;
