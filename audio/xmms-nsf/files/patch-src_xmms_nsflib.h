--- src/xmms/nsflib.h.orig	2000-07-23 10:05:21 UTC
+++ src/xmms/nsflib.h
@@ -1,10 +1,11 @@
 typedef signed short Int16;
 typedef unsigned int Uint;
+typedef unsigned int Uint32;
 typedef unsigned char Uint8;
 
 Uint NSFLoad(Uint8 *pData, Uint uSize);
 void NSFSetSongNo(Uint uSongNo);
 void NESAudioFrequencySet(Uint freq);
 void NESReset(void);
-void NESAudioRender(Int16 *bufp, Uint buflen);
+Uint32 NESAudioRender(Int16 *bufp, Uint buflen);
 void NESTerminate(void);
