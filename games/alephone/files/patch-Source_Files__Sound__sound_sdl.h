--- Source_Files/Sound/sound_sdl.h.orig	Sat Aug 12 09:43:24 2006
+++ Source_Files/Sound/sound_sdl.h	Sat Aug 12 09:44:25 2006
@@ -346,6 +346,7 @@
 #ifdef MUSIC_SDL
 bool load_music_sdl(FileSpecifier &song_file)
 {
+	if (!_sm_initialized || !_sm_active) return false;
 	sdl_channel *c = sdl_channels + MUSIC_CHANNEL;	// Music channel
 	uint32 music_sample_rate;						// Music sample rate in Hz
 
