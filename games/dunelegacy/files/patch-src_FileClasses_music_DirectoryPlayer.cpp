--- src/FileClasses/music/DirectoryPlayer.cpp.orig	2016-11-20 14:57:02 UTC
+++ src/FileClasses/music/DirectoryPlayer.cpp
@@ -61,7 +61,7 @@ DirectoryPlayer::DirectoryPlayer() : MusicPlayer(setti
 
     music = nullptr;
 
-    Mix_Init(MIX_INIT_FLUIDSYNTH | MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
+    Mix_Init(MIX_INIT_MID | MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
 }
 
 DirectoryPlayer::~DirectoryPlayer() {
