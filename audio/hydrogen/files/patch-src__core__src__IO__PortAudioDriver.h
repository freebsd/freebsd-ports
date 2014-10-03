--- src/core/src/IO/PortAudioDriver.h.orig	2014-09-09 18:39:33 UTC
+++ src/core/src/IO/PortAudioDriver.h
@@ -31,7 +31,11 @@
 #ifdef H2CORE_HAVE_PORTAUDIO
 
 #include <inttypes.h>
+#if defined(__FreeBSD__)
+#include <portaudio2/portaudio.h>
+#else
 #include <portaudio.h>
+#endif
 
 namespace H2Core
 {
