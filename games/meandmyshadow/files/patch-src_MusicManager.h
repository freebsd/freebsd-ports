--- src/MusicManager.h.orig	2018-11-03 03:51:57 UTC
+++ src/MusicManager.h
@@ -20,12 +20,11 @@
 #ifndef MUSICMANAGER_H
 #define MUSICMANAGER_H
 
+#include <SDL2/SDL_mixer.h>
+
 #include <string>
 #include <map>
 #include <vector>
-
-struct _Mix_Music;
-typedef struct _Mix_Music Mix_Music;
 
 //Class for loading and playing the music.
 class MusicManager{
