--- Src/dsSDLMixer/driver_sdlmixer.c.orig	Tue Aug 31 21:53:06 2004
+++ Src/dsSDLMixer/driver_sdlmixer.c	Tue Aug 31 21:53:21 2004
@@ -130,7 +130,7 @@
 		return false;
 	}
 
-	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024))
+	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096))
 	{
 		Error();
 		return false;
