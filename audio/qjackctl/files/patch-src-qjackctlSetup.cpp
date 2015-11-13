--- src/qjackctlSetup.cpp.orig	2015-07-15 13:30:36 UTC
+++ src/qjackctlSetup.cpp
@@ -34,7 +34,7 @@
 #if defined(WIN32)
 #define DEFAULT_DRIVER "portaudio"
 #else
-#define DEFAULT_DRIVER "alsa"
+#define DEFAULT_DRIVER "oss"
 #endif
 
 
