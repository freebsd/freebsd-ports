--- src/soundmanagerconfig.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/soundmanagerconfig.cpp
@@ -290,7 +290,7 @@ void SoundManagerConfig::loadDefaults(So
     if (flags & SoundManagerConfig::API) {
         QList<QString> apiList = soundManager->getHostAPIList();
         if (!apiList.isEmpty()) {
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
             //Check for JACK and use that if it's available, otherwise use ALSA
             if (apiList.contains(MIXXX_PORTAUDIO_JACK_STRING)) {
                 m_api = MIXXX_PORTAUDIO_JACK_STRING;
