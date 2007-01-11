--- ./src/nes/audiosys.h.orig	Sun Jan  7 05:17:56 2001
+++ ./src/nes/audiosys.h	Wed Jan 10 20:10:34 2007
@@ -21,7 +21,7 @@
 } NES_VOLUME_HANDLER;
 
 
-void NESAudioRender(Int16 *bufp, Uint buflen);
+Uint32 NESAudioRender(Int16 *bufp, Uint buflen);
 void NESAudioHandlerInstall(NES_AUDIO_HANDLER *ph);
 void NESAudioFrequencySet(Uint freq);
 Uint NESAudioFrequencyGet(void);
