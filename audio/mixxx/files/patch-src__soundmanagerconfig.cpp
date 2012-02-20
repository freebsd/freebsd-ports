--- src/soundmanagerconfig.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/soundmanagerconfig.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -290,7 +290,7 @@
     if (flags & SoundManagerConfig::API) {
         QList<QString> apiList = soundManager->getHostAPIList();
         if (!apiList.isEmpty()) {
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
             //Check for JACK and use that if it's available, otherwise use ALSA
             if (apiList.contains(MIXXX_PORTAUDIO_JACK_STRING)) {
                 m_api = MIXXX_PORTAUDIO_JACK_STRING;
