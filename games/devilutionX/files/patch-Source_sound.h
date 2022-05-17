--- Source/sound.h.orig	2022-05-17 15:57:06 UTC
+++ Source/sound.h
@@ -60,7 +60,11 @@ struct TSnd {
 };
 
 extern bool gbSndInited;
+#ifndef NOSOUND
 extern _music_id sgnMusicTrack;
+#else
+inline const _music_id sgnMusicTrack = NUM_MUSIC;
+#endif
 
 void ClearDuplicateSounds();
 void snd_stop_snd(TSnd *pSnd);
