--- src/client/Sounds.cpp.orig	2008-10-07 17:54:58.000000000 +0400
+++ src/client/Sounds.cpp	2008-10-13 04:19:09.000000000 +0400
@@ -144,36 +144,15 @@
 	if(SoundSystemAvailable) return true;
 	SoundSystemAvailable = false;
 
-	if(getenv("SDL_AUDIODRIVER"))
-		printf("SDL_AUDIODRIVER=%s\n", getenv("SDL_AUDIODRIVER"));
-#if !defined(WIN32) && !defined(MACOSX)
-	if(!getenv("SDL_AUDIODRIVER")) {
-		printf("SDL_AUDIODRIVER not set, setting to ALSA\n");
-		putenv((char*)"SDL_AUDIODRIVER=alsa");
-	}
-#endif
-
-initSoundSystem:
-
 	// HINT: other SDL stuff is already inited, we don't care here
 	if( SDL_InitSubSystem(SDL_INIT_AUDIO) != 0 ) {
 		printf("InitSoundSystem: Unable to initialize SDL-sound: %s\n", SDL_GetError());
-		if(getenv("SDL_AUDIODRIVER")) {
-			printf("trying again with SDL_AUDIODRIVER unset\n");
-			unsetenv("SDL_AUDIODRIVER");
-			goto initSoundSystem;
-		} else
-			return false;
+		return false;
 	}
 
 	if(Mix_OpenAudio(rate, AUDIO_S16, channels, buffers)) {
 		printf("InitSoundSystem: Unable to open audio (SDL_mixer): %s\n", Mix_GetError());
-		if(getenv("SDL_AUDIODRIVER")) {
-			printf("trying again with SDL_AUDIODRIVER unset\n");
-			unsetenv("SDL_AUDIODRIVER");
-			goto initSoundSystem;
-		} else
-			return false;
+		return false;
 	}
 
 	int allocChanNum = Mix_AllocateChannels(1000); // TODO: enough?
