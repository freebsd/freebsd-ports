--- ./src/mod.c.orig	Sat Oct  8 14:08:32 2005
+++ ./src/mod.c	Tue May 16 14:33:39 2006
@@ -30,14 +30,17 @@
 
 void MOD_stop (void)
 {
+#if 0
 	if (modplaying) {
 		FMUSIC_FreeSong (mod);
 	}
 	modplaying = 0;
+#endif
 }
 
 void MOD_play (void)
 {
+#if 0
 	char	modname[256], *buffer;
 	int		mark;
 
@@ -69,10 +72,12 @@
 
 	modplaying = 1;
 	FMUSIC_PlaySong (mod);
+#endif
 }
 
 void MOD_init (void)
 {
+#if 0
 	FSOUND_SetBufferSize (300);
 	if (!FSOUND_Init(11025, 32, 0))	{
 		Con_Printf ("%s\n", FMOD_ErrorString(FSOUND_GetError()));
@@ -109,10 +114,13 @@
 
 	Cmd_AddCommand ("stopmod", MOD_stop);
 	Cmd_AddCommand ("playmod", MOD_play);
+#endif
 };
 
 void MOD_done (void)
 {
+#if 0
 	FSOUND_Close ();
+#endif
 };
 #endif
