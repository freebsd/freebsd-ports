--- source/s_sdl.cpp.orig	Sat Mar  8 14:08:04 2003
+++ source/s_sdl.cpp	Wed Jan 21 15:41:52 2004
@@ -82,8 +82,8 @@
 
 IMPLEMENT_CLASS(VDefaultSoundDevice);
 
-static TCvarI mix_frequency		("mix_frequency", "22050", CVAR_ARCHIVE);
-static TCvarI mix_bits			("mix_bits",      "16",    CVAR_ARCHIVE);
+static TCvarI mix_frequency		("mix_frequency", "44100", CVAR_ARCHIVE);
+static TCvarI mix_bits			("mix_bits",      "8",    CVAR_ARCHIVE);
 static TCvarI mix_channels		("mix_channels",  "2",     CVAR_ARCHIVE);
 
 static TCvarI mix_chunksize		("mix_chunksize", "4096",  CVAR_ARCHIVE);
@@ -107,6 +107,8 @@
 static TVec listener_forward;
 static TVec listener_right;
 static TVec listener_up;
+
+SDL_AudioCVT wavecvt;
 
 // CODE --------------------------------------------------------------------
 
@@ -337,6 +339,12 @@
 	mix_bits = fmt & 0xFF;
 	mix_channels = ch;
 
+        if (SDL_BuildAudioCVT(&wavecvt, AUDIO_S8, 2, 4096,
+                fmt, mix_channels, mix_frequency) == -1) {
+	  Sys_Error("SDL_BuildAudioCVT: failed.\n");
+	  return;
+        }
+
 	channels = Z_CNew<channel_t>(mix_voices);
 	for (i = 0; i < mix_voices; i++)
 	{
@@ -425,13 +433,23 @@
 		return;
 	}
 
-	// copy the lump to a SDL_Mixer chunk...
-	chunk = Mix_LoadRAW_RW(SDL_RWFromMem((void*)S_sfx[sound_id].data, 
-		S_sfx[sound_id].len), 0, S_sfx[sound_id].freq, AUDIO_U8, 1);
-	if (chunk == NULL)
-		Sys_Error("Mix_LoadRAW_RW() failed!\n");
-	voice = Mix_LoadChannel(-1, chunk, 0);
-
+        wavecvt.len = S_sfx[sound_id].len;
+        wavecvt.buf = (Uint8*)malloc(wavecvt.len*wavecvt.len_mult);
+        memcpy(wavecvt.buf, S_sfx[sound_id].data, S_sfx[sound_id].len);
+        
+        if (SDL_ConvertAudio(&wavecvt) == -1) {
+          Sys_Error("SDL_ConvertAudio: error during conversion\n");
+          return;
+        }
+        
+        // copy the lump to a SDL_Mixer chunk...
+        chunk = Mix_QuickLoad_RAW((Uint8*)wavecvt.buf,
+                        wavecvt.len*wavecvt.len_mult);                        
+        if (chunk == NULL)
+                Sys_Error("Mix_QuickLoad_RAW() failed!\n");
+                
+        voice = Mix_PlayChannel(-1, chunk, 0);
+
 	if (voice < 0)
 	{
 		S_DoneWithLump(sound_id);
@@ -448,9 +466,6 @@
 	pitch = CalcPitch(S_sfx[sound_id].freq, sound_id);
 #warning how to set the pitch? (CS)
 
-	// ready to go...
-	Mix_Play(voice);
-
 	channels[chan].origin_id = origin_id;
 	channels[chan].origin    = origin;
 	channels[chan].channel   = channel;
@@ -501,22 +516,28 @@
 		return;
 	}
 
-	// copy the lump to a SDL_Mixer chunk...
-	chunk = Mix_LoadRAW_RW(SDL_RWFromMem((void*)S_VoiceInfo.data, 
-		S_VoiceInfo.len), 0, S_VoiceInfo.freq, AUDIO_U8, 1);
-	if (chunk == NULL)
-		Sys_Error("Mix_LoadRAW_RW() failed!\n");
-	voice = Mix_LoadChannel(-1, chunk, 0);
-
+        wavecvt.len = S_sfx[VOICE_SOUND_ID].len;
+        wavecvt.buf = (Uint8*)malloc(wavecvt.len*wavecvt.len_mult);
+        memcpy(wavecvt.buf, S_sfx[VOICE_SOUND_ID].data, S_sfx[VOICE_SOUND_ID].len);
+        
+        if (SDL_ConvertAudio(&wavecvt) == -1) {
+          Sys_Error("SDL_ConvertAudio: error during conversion\n");
+          return;
+        }
+        // copy the lump to a SDL_Mixer chunk...
+        chunk = Mix_QuickLoad_RAW((Uint8*)wavecvt.buf,
+                        wavecvt.len*wavecvt.len_mult);
+        if (chunk == NULL)
+                Sys_Error("Mix_QuickLoad_RAW() failed!\n");
+                
+        voice = Mix_PlayChannel(-1, chunk, 0);
+        
 	if (voice < 0)
 	{
 		S_DoneWithLump(VOICE_SOUND_ID);
 		return;
 	}
 
-	// ready to go...
-	Mix_Play(voice);
-
 	channels[chan].origin_id = 0;
 	channels[chan].origin    = TVec(0, 0, 0);
 	channels[chan].channel   = 1;
@@ -558,19 +579,26 @@
 		return;
 	}
 
-	chunk = Mix_LoadRAW_RW(SDL_RWFromMem((void*)S_sfx[sound_id].data,
-		S_sfx[sound_id].len), 0, S_sfx[sound_id].freq, AUDIO_U8, 1);
-	if (chunk == NULL)
-		Sys_Error("Mix_LoadRAW_RW() failed!\n");
-
-	voice = Mix_LoadChannel(-1, chunk, 0);
+        wavecvt.len = S_sfx[sound_id].len;
+        wavecvt.buf = (Uint8*)malloc(wavecvt.len*wavecvt.len_mult);
+        memcpy(wavecvt.buf, S_sfx[sound_id].data, S_sfx[sound_id].len);
+        
+        if (SDL_ConvertAudio(&wavecvt) == -1) {
+          Sys_Error("SDL_ConvertAudio: error during conversion\n");
+          return;
+        }
+        // copy the lump to a SDL_Mixer chunk...
+        chunk = Mix_QuickLoad_RAW((Uint8*)wavecvt.buf,
+                        wavecvt.len*wavecvt.len_mult);
+        if (chunk == NULL)
+                Sys_Error("Mix_QuickLoad_RAW() failed!\n");
+                
+        voice = Mix_PlayChannel(-1, chunk, 0);
 
 	if (voice < 0)
 	{
 		return;
 	}
-
-	Mix_Play(voice);
 
 	start = Sys_Time();
 	while (1)
