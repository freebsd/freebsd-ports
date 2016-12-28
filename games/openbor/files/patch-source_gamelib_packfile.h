Don't crash with > 80 tracks.

--- source/gamelib/packfile.h.orig	2015-04-18 21:22:03 UTC
+++ source/gamelib/packfile.h
@@ -42,7 +42,7 @@ typedef struct fileliststruct
 {
     char filename[128];
     int nTracks;
-    char bgmFileName[80][256];
+    char bgmFileName[256][80];
     int bgmTrack;
     unsigned int bgmTracks[256];
 #ifdef SDL
