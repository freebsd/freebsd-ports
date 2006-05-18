--- ./src/cdaudio.h.orig	Thu Nov  3 16:03:41 2005
+++ ./src/cdaudio.h	Tue May 16 14:33:39 2006
@@ -26,7 +26,7 @@
 void CDAudio_Shutdown(void);
 void CDAudio_Update(void);
 //QuDos-
-#ifdef __linux__ //Thx quake2 icculus
+#ifdef __unix__ //Thx quake2 icculus
 void CDAudio_RandomPlay(void);
 #endif
 //-QuDos
