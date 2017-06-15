--- src/backend/CPortAudioSoundPlayer.cpp.orig	2013-12-27 03:56:49 UTC
+++ src/backend/CPortAudioSoundPlayer.cpp
@@ -73,7 +73,7 @@ void CPortAudioSoundPlayer::initialize()
 		// open a PortAudio stream
 #ifdef ENABLE_PORTAUDIO_V19
 		PaStreamParameters output = { gPortAudioOutputDevice, 
-			gDesiredOutputChannelCount, 
+			static_cast<int>(gDesiredOutputChannelCount),
 			sampleFormat,
 			Pa_GetDeviceInfo(gPortAudioOutputDevice)->defaultLowOutputLatency ,
 			NULL};
