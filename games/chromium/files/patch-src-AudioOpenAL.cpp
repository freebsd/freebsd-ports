--- src/AudioOpenAL.cpp.orig	Thu Mar 30 15:34:34 2006
+++ src/AudioOpenAL.cpp	Thu Mar 30 16:32:00 2006
@@ -153,13 +153,8 @@
 
 		checkError("AudioOpenAL::~Audio()");
 
-		#ifdef _WIN32
 		if(context_id)
 			alcDestroyContext((ALCcontext*)context_id);
-		#else
-		if(context_id)
-			alcDestroyContext(context_id);
-		#endif
 		
 		fprintf(stderr, "done.\n");
 	}
@@ -200,7 +195,7 @@
 	ALCdevice *dev;
 	dev = alcOpenDevice( NULL );
 	context_id = alcCreateContext(dev, NULL);
-	alcMakeContextCurrent(context_id);
+	alcMakeContextCurrent((ALCcontext*)context_id);
 #endif
 #endif
 
@@ -310,7 +305,7 @@
 				
 	//-- check AttenuationScale extension
 	alAttenuationScale = (void (*)(ALfloat param))
-						alGetProcAddress((ALubyte *)"alAttenuationScale_LOKI");
+						alGetProcAddress((ALchar *)"alAttenuationScale_LOKI");
 	if(alAttenuationScale == NULL) 
 		fprintf(stderr, "ATTENTION!! Could not load alAttenuationScale\n");
 	else
@@ -318,9 +313,9 @@
 	
 	//-- check Audio Channel extension
 	alcGetAudioChannel = (float (*)(ALuint channel))
-						alGetProcAddress((const ALubyte *)"alcGetAudioChannel_LOKI");
+						alGetProcAddress((const ALchar *)"alcGetAudioChannel_LOKI");
 	alcSetAudioChannel = (void (*)(ALuint channel, ALfloat volume))
-						alGetProcAddress((const ALubyte *)"alcSetAudioChannel_LOKI");
+						alGetProcAddress((const ALchar *)"alcSetAudioChannel_LOKI");
 #ifdef CD_VOLUME
 	if(alcGetAudioChannel)
 		origCDvolume = alcGetAudioChannel(ALC_CHAN_CD_LOKI);
@@ -328,10 +323,10 @@
 	
 	//-- check MP3 extension
 	alutLoadMP3 = (ALboolean (*)(ALuint, ALvoid *, ALint))
-		alGetProcAddress((const ALubyte *)"alutLoadMP3_LOKI");
+		alGetProcAddress((const ALchar *)"alutLoadMP3_LOKI");
 	//-- check Ogg/Vorbis extension
 	alutLoadVorbis = (ALboolean (*)(ALuint, ALvoid *, ALint))
-		alGetProcAddress((const ALubyte *)"alutLoadVorbis_LOKI");
+		alGetProcAddress((const ALchar *)"alutLoadVorbis_LOKI");
 
 #endif //_WIN32
 }
@@ -471,6 +466,7 @@
 	ALsizei size, freq, bits;
 	ALenum format;
 	ALvoid *data;
+	ALboolean loop;
 
 	for(i = 0; i < NumSoundTypes; i++)
 	{
@@ -481,7 +477,7 @@
 		else
 		{
 #ifndef _WIN32
-			alutLoadWAV(dataLoc(fileNames[i]), &data, &format, &size, &bits, &freq);
+			alutLoadWAVFile((ALbyte*)dataLoc(fileNames[i]), &format, &data, &size, &freq, &loop);
 			alBufferData (buffer[i], format, data, size, freq);
 			free(data);
 #else //_WIN32
