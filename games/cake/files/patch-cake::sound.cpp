--- cake/sound.cpp.orig	Fri Jul 16 22:11:47 2004
+++ cake/sound.cpp	Sat Jul 17 00:31:09 2004
@@ -1,8 +1,9 @@
+#include "sound.h"
+
+#if ENABLE_SOUND
 #define FMOD_DYN_IMPL
 #define FMOD_DYN_NOASSERT
 
-#include "sound.h"
-
 #include "cake.h"
 #include "vars.h"
 #include "commands.h"
@@ -136,12 +137,13 @@
 		gConsole->Insertln("usage: %s <value>", argv[0]);
 	}
 }
+#endif
 
 bool initSoundSystem(void)
 {
 	#if !ENABLE_SOUND
 		return false;
-	#endif
+	#else
 
 	int i;
 
@@ -249,13 +251,14 @@
 			return false;
 		}
 	}
+	#endif
 }
 
 void shutdownSoundSystem(void)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	freeBGMusic();
 	freeSound();
@@ -271,13 +274,14 @@
 	gCommands->RemoveCommand("snd_distancefactor");
 	gVars->UnregisterVar(snd_mindistance);
 	gVars->UnregisterVar(snd_maxdistance);
+	#endif
 }
 
 void setBGMusic(const char* filename, bool start_paused)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	freeBGMusic();
 
@@ -409,13 +413,14 @@
 		FSOUND_SetVolume(bgmusic[0].channel, musicvolume);
 		if (!start_paused) FSOUND_SetPaused(bgmusic[0].channel, FALSE);
 	}
+	#endif
 }
 
 void toggleBGMusicPause(void)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	for (int i = 0; i < BGMUSIC_CHANNELS; ++i)
 	{
@@ -427,13 +432,14 @@
 				FSOUND_SetPaused(bgmusic[i].channel, TRUE);
 		}
 	}
+	#endif
 }
 
 void playSound(int num, float x, float y, float z, bool stop_if_playing)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	if (num < 0 || num >= SOUND_CHANNELS) return;
 	if (!sounds[num].sample || sounds[num].free) return;
@@ -441,13 +447,14 @@
 	vec3_t pos;
 	VectorSet(pos, x, y, z);
 	playSound(num, pos, stop_if_playing);
+	#endif
 }
 
 void playSound(int num, vec3_t location, bool stop_if_playing)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	if (num < 0 || num >= SOUND_CHANNELS) return;
 	if (!sounds[num].sample || sounds[num].free) return;
@@ -472,26 +479,28 @@
 	}
 
 	FSOUND_SetVolume(sounds[num].channel, soundvolume);
+	#endif
 }
 
 int loadSound(const char *filename, float x, float y, float z, bool loop, bool start_playing, bool start_paused)
 {
 	#if !ENABLE_SOUND
 		return -1;
-	#endif
+	#else
 
 	if (!filename || !strlen(filename)) return -1;
 
 	vec3_t pos;
 	VectorSet(pos, x, y, z);
 	return loadSound(filename, pos, loop, start_playing, start_paused);
+	#endif
 }
 
 int loadSound(const char *filename, vec3_t location, bool loop, bool start_playing, bool start_paused)
 {
 	#if !ENABLE_SOUND
 		return -1;
-	#endif
+	#else
 
 	if (!filename || !strlen(filename)) return -1;
 
@@ -594,13 +603,14 @@
 	}
 
 	return freesound;
+	#endif
 }
 
 int load3DSound(const char *filename, vec3_t location, bool loop, bool start_playing, bool start_paused)
 {
 	#if !ENABLE_SOUND
 		return -1;
-	#endif
+	#else
 
 	if (!filename || !strlen(filename)) return -1;
 
@@ -608,13 +618,14 @@
 	if (!location) VectorClear(pos);
 	else VectorCopy(location, pos);
 	return loadSound(filename, pos, loop, start_playing, start_paused);
+	#endif
 }
 
 void toggleSoundPause(int num)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	if (num < 0 || num >= SOUND_CHANNELS)
 	{
@@ -630,13 +641,14 @@
 				FSOUND_SetPaused(sounds[num].channel, TRUE);
 		}
 	}
+	#endif
 }
 
 void SoundUpdate(vec3_t position, vec3_t forward)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	// update background music
 	if (playing_intro)
@@ -675,13 +687,14 @@
 
 	FSOUND_3D_Listener_SetAttributes(pos, NULL, forward[0], forward[2], forward[1], 0, 1, 0);
 	FSOUND_Update();
+	#endif
 }
 
 void freeBGMusic(int num)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	if (num < 0 || num >= BGMUSIC_CHANNELS)
 	{
@@ -710,13 +723,14 @@
 			bgmusic[num].free = true;
 		}
 	}
+	#endif
 }
 
 void freeSound(int num)
 {
 	#if !ENABLE_SOUND
 		return;
-	#endif
+	#else
 
 	if (num < 0 || num >= SOUND_CHANNELS)
 	{
@@ -745,13 +759,14 @@
 			sounds[num].free = true;
 		}
 	}
+	#endif
 }
 
 const char* GetSoundErrorString(int errnum)
 {
 	#if !ENABLE_SOUND
 		return NULL;
-	#endif
+	#else
 
 	switch (errnum)
 	{
@@ -777,4 +792,5 @@
 		case FMOD_ERR_NONE:
 		default: return "^1No errors";
 	}
+	#endif
 }
