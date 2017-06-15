--- src/backend/CPortAudioSoundRecorder.cpp.orig	2013-12-27 03:57:19 UTC
+++ src/backend/CPortAudioSoundRecorder.cpp
@@ -70,7 +70,7 @@ void CPortAudioSoundRecorder::initialize
 #ifdef ENABLE_PORTAUDIO_V19
 		PaStreamParameters input = { 
                         gPortAudioOutputDevice, 
-                        sound->getChannelCount(), 
+                        static_cast<int>(sound->getChannelCount()),
                         sampleFormat, 
                         Pa_GetDeviceInfo(gPortAudioOutputDevice)->defaultLowInputLatency ,
                         NULL};
