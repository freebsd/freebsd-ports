--- src/dsp/engine_jack.c.orig	2026-06-11 22:37:27 UTC
+++ src/dsp/engine_jack.c
@@ -37,6 +37,10 @@
 
 #  include <jack/thread.h>
 
+#if defined(__FreeBSD__)
+#  include <dlfcn.h>
+#endif
+
 typedef enum
 {
   Z_AUDIO_ENGINE_JACK_ERROR_FAILED,
