--- ./src/neh.c.orig	Tue Sep 27 13:57:57 2005
+++ ./src/neh.c	Tue May 16 17:47:21 2006
@@ -5,8 +5,10 @@
 #endif
 
 #include "neh.h"
+#if 0
 #include "fmod/fmod.h"
 #include "fmod/fmod_errors.h"
+#endif
 
 int     smoketexture, DoFullbright;
 int     NehGameType = 0;
@@ -77,22 +79,27 @@
 
 void MOD_stop (void)
 {
+#if 0
 	if (modplaying)
 		FMUSIC_FreeSong (mod);
 
 	modplaying = 0;
+#endif
 }
 
 void MOD_SetVolume_f (void)
 {
+#if 0
 	if (!modplaying)
 		return;
 
 	FMUSIC_SetMasterVolume (mod, modvolume.value * 128);
+#endif
 }
 
 void MOD_play (void)
 {
+#if 0
 	static char modname[256];
 	char	    modfile[256];
 	char	    *buffer;
@@ -137,10 +144,12 @@
 	modplaying = 1;
 	MOD_SetVolume_f ();
 	FMUSIC_PlaySong (mod);
+#endif
 }
 
 void MOD_init(void)
 {
+#if 0
 	if (COM_CheckParm("-nosound"))
 		return;
 
@@ -169,11 +178,14 @@
 	Cvar_RegisterVariable (&modvolume);
 	Cmd_AddCommand ("stopmod",MOD_stop);
 	Cmd_AddCommand ("playmod",MOD_play);
+#endif
 }
 
 void MOD_done (void)
 {
+#if 0
 	FSOUND_Close ();
+#endif
 }
 
 void pausedemo (void)
