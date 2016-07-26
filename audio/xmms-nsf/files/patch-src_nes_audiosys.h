--- src/nes/audiosys.h.orig	2001-01-07 04:17:56 UTC
+++ src/nes/audiosys.h
@@ -21,7 +21,7 @@ typedef struct NES_VOLUME_HANDLER_TAG {
 } NES_VOLUME_HANDLER;
 
 
-void NESAudioRender(Int16 *bufp, Uint buflen);
+Uint32 NESAudioRender(Int16 *bufp, Uint buflen);
 void NESAudioHandlerInstall(NES_AUDIO_HANDLER *ph);
 void NESAudioFrequencySet(Uint freq);
 Uint NESAudioFrequencyGet(void);
