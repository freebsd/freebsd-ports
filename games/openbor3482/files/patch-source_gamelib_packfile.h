Don't crash with > 80 tracks.

--- source/gamelib/packfile.h.orig	2011-04-08 16:22:58 UTC
+++ source/gamelib/packfile.h
@@ -40,7 +40,7 @@ typedef struct pnamestruct{
 typedef struct fileliststruct{
 	char filename[128];
 	int nTracks;
-	char bgmFileName[80][256];
+	char bgmFileName[256][80];
 	int bgmTrack;
 	unsigned int bgmTracks[256];
 #ifdef SDL
