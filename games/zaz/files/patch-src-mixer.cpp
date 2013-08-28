--- src/mixer.cpp.orig	2010-01-31 06:55:48.000000000 +0300
+++ src/mixer.cpp	2013-08-28 03:29:50.975228551 +0400
@@ -23,7 +23,7 @@
 
 namespace Scenes
 {
-Mixer::Mixer(MixerMode mmode = Realtime)
+Mixer::Mixer(MixerMode mmode)
         : mode(mmode), isPlaying(false)
 {
     mut_disposeList = SDL_CreateMutex();
