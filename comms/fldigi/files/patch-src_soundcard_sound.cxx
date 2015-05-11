--- src/soundcard/sound.cxx.orig	2015-05-11 09:19:59 UTC
+++ src/soundcard/sound.cxx
@@ -689,7 +689,7 @@ size_t SoundOSS::Read(float *buffer, siz
 
 	for (size_t i = 0; i < buffersize; i++)
 		buffer[i] = src_buffer[2*i + 
-							   progdefaults.ReverseRxAudio ? 1 : 0];
+							   (progdefaults.ReverseRxAudio ? 1 : 0)];
 
 #if USE_SNDFILE
 	if (capture)
@@ -724,7 +724,7 @@ size_t SoundOSS::Read(float *buffer, siz
 
 	for (int i = 0; i < numread; i++)
 		buffer[i] = snd_buffer[2*i +
-							   progdefaults.sig_on_right_channel ? 1 : 0];
+							   (progdefaults.sig_on_right_channel ? 1 : 0)];
 
 	return numread;
 
