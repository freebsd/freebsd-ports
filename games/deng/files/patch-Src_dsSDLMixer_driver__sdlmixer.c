--- Src/dsSDLMixer/driver_sdlmixer.c.orig	Thu Aug 26 19:07:44 2004
+++ Src/dsSDLMixer/driver_sdlmixer.c	Thu Aug 26 19:11:15 2004
@@ -117,7 +117,7 @@
 		return false;
 	}
 
-	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024))
+	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096))
 	{
 		Error();
 		return false;
