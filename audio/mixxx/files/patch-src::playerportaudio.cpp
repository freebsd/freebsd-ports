--- src/playerportaudio.cpp.orig	Fri Jun 25 20:53:49 2004
+++ src/playerportaudio.cpp	Fri Jun 25 20:54:03 2004
@@ -381,7 +381,7 @@
 
 QString PlayerPortAudio::getSoundApi()
 {
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     return QString("OSS");
 #endif
 #ifdef __MACX__
