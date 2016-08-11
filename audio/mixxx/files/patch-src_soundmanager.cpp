--- src/soundmanager.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/soundmanager.cpp
@@ -234,7 +234,7 @@ void SoundManager::queryDevices() {
 #ifdef __PORTAUDIO__
     PaError err = paNoError;
     if (!m_paInitialized) {
-#ifdef Q_OS_LINUX
+#if defined(__BSD__) || defined(Q_OS_LINUX)
         setJACKName();
 #endif
         err = Pa_Initialize();
@@ -626,9 +626,9 @@ QList<AudioInput> SoundManager::register
 
 void SoundManager::setJACKName() const {
 #ifdef __PORTAUDIO__
-#ifdef Q_OS_LINUX
+#if defined(__BSD__) || defined(Q_OS_LINUX)
     typedef PaError (*SetJackClientName)(const char *name);
-    QLibrary portaudio("libportaudio.so.2");
+    QLibrary portaudio("libportaudio.so");
     if (portaudio.load()) {
         SetJackClientName func(
             reinterpret_cast<SetJackClientName>(
