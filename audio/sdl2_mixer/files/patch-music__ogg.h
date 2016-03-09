--- music_ogg.h.orig	2013-08-10 17:39:58 UTC
+++ music_ogg.h
@@ -26,7 +26,7 @@
 /* This file supports Ogg Vorbis music streams */
 
 #ifdef OGG_USE_TREMOR
-#include <ivorbisfile.h>
+#include <tremor/ivorbisfile.h>
 #else
 #include <vorbis/vorbisfile.h>
 #endif
