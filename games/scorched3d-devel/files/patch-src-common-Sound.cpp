--- src/common/Sound.cpp.orig	Sun May 30 23:32:44 2004
+++ src/common/Sound.cpp	Sun May 30 23:07:33 2004
@@ -73,7 +73,7 @@
 
 bool Sound::init()
 {
-	if ( Mix_OpenAudio(11025, AUDIO_U8, 1, 512) < 0 ) 
+	if ( Mix_OpenAudio(11025, AUDIO_U8, 1, 2048) < 0 ) 
 	{
 		dialogMessage(SDL_GetError(), 
 			"Warning: Couldn't set 11025 Hz 8-bit audio");
