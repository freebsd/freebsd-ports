--- ./src/xmms/nsflib.h.orig	Sun Jul 23 12:05:21 2000
+++ ./src/xmms/nsflib.h	Wed Jan 10 20:10:34 2007
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
