--- src/qjackctlSetup.cpp.orig	2016-04-05 15:57:30 UTC
+++ src/qjackctlSetup.cpp
@@ -34,7 +34,7 @@
 #if defined(WIN32)
 #define DEFAULT_DRIVER "portaudio"
 #else
-#define DEFAULT_DRIVER "alsa"
+#define DEFAULT_DRIVER "oss"
 #endif
 
 
