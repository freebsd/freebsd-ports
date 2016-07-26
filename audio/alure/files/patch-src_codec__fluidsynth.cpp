--- src/codec_fluidsynth.cpp.orig	2011-07-29 08:37:48 UTC
+++ src/codec_fluidsynth.cpp
@@ -27,6 +27,7 @@
 
 #include <string.h>
 #include <assert.h>
+#include <unistd.h>
 #ifdef _WIN32
 #include <io.h>
 #endif
