--- src/drivers/Qt/sdl-sound.cpp.orig	2022-01-21 20:48:31 UTC
+++ src/drivers/Qt/sdl-sound.cpp
@@ -219,8 +219,7 @@ InitSound()
 	spec.freq = s_SampleRate = soundrate;
 	spec.format = AUDIO_S16SYS;
 	spec.channels = 1;
-	//spec.samples = 512;
-	spec.samples = (int)( ( (double)s_SampleRate / getBaseFrameRate() ) );
+	spec.samples = 512;
 	spec.callback = fillaudio;
 	spec.userdata = 0;
 
