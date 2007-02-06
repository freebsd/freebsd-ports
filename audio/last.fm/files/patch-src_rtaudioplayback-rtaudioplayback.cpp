--- src/rtaudioplayback/rtaudioplayback.cpp.orig	Tue Feb  6 00:09:15 2007
+++ src/rtaudioplayback/rtaudioplayback.cpp	Tue Feb  6 00:09:41 2007
@@ -204,7 +204,7 @@
         LOGL( 3, "Card ID " << settingsService()->soundCard() << " - translated to internal ID " << card );
 
         #ifdef Q_WS_X11
-        api = RtAudio::LINUX_ALSA;
+        api = RtAudio::LINUX_OSS;
         #endif
 
         RtAudioDeviceInfo info = m_audio->getDeviceInfo( card );
