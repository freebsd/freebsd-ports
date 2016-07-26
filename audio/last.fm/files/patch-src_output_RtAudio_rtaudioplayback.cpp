--- src/output/RtAudio/rtaudioplayback.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/output/RtAudio/rtaudioplayback.cpp
@@ -158,7 +158,7 @@ RtAudioPlayback::soundSystems()
     #endif
 
     #ifdef Q_WS_X11
-        l << "Alsa";
+        l << "OSS";
     #endif
 
     #ifdef Q_WS_MAC
@@ -284,7 +284,7 @@ RtAudioPlayback::initAudio(
         int card = internalSoundCardID( m_deviceNum );
 
         #ifdef Q_WS_X11
-        api = RtAudio::LINUX_ALSA;
+        api = RtAudio::LINUX_OSS;
         #endif
 
         RtAudioDeviceInfo info = m_audio->getDeviceInfo( card );
