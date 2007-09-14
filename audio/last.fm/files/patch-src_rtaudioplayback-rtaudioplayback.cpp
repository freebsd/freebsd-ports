--- src/output/RtAudio/rtaudioplayback.cpp.orig	2007-09-13 13:46:07.000000000 +0200
+++ src/output/RtAudio/rtaudioplayback.cpp	2007-09-14 20:54:41.000000000 +0200
@@ -157,7 +157,7 @@
     #endif
 
     #ifdef Q_WS_X11
-        l << "Alsa";
+        l << "OSS";
     #endif
 
     #ifdef Q_WS_MAC
@@ -280,7 +280,7 @@
         int card = internalSoundCardID( The::settings().soundCard() );
 
         #ifdef Q_WS_X11
-        api = RtAudio::LINUX_ALSA;
+        api = RtAudio::LINUX_OSS;
         #endif
 
         RtAudioDeviceInfo info = m_audio->getDeviceInfo( card );
