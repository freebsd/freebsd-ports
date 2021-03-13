--- src/FileClasses/music/XMIPlayer.cpp.orig	2016-11-17 23:06:11 UTC
+++ src/FileClasses/music/XMIPlayer.cpp
@@ -32,7 +32,7 @@
 XMIPlayer::XMIPlayer() : MusicPlayer(settings.audio.playMusic, settings.audio.musicVolume) {
     music = nullptr;
 
-    if((Mix_Init(MIX_INIT_FLUIDSYNTH) & MIX_INIT_FLUIDSYNTH) == 0) {
+    if((Mix_Init(MIX_INIT_MID) & MIX_INIT_MID) == 0) {
         SDL_Log("XMIPlayer: Failed to init required midi support: %s", SDL_GetError());
     }
 }
