--- dynamic_ogg.h.orig	2013-08-10 17:39:55 UTC
+++ dynamic_ogg.h
@@ -21,7 +21,7 @@
 
 #ifdef OGG_MUSIC
 #ifdef OGG_USE_TREMOR
-#include <ivorbisfile.h>
+#include <tremor/ivorbisfile.h>
 #else
 #include <vorbis/vorbisfile.h>
 #endif
