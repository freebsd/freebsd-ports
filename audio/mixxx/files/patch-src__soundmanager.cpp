--- src/soundmanager.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/soundmanager.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -309,7 +309,7 @@
 #ifdef __PORTAUDIO__
     PaError err = paNoError;
     if (!m_paInitialized) {
-#ifdef Q_OS_LINUX
+#if defined(__BSD__) || defined(Q_OS_LINUX)
         setJACKName();
 #endif
         err = Pa_Initialize();
@@ -702,9 +702,9 @@
 
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
