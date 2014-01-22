--- ./src/codec_fluidsynth.cpp.orig	2011-07-29 10:37:48.000000000 +0200
+++ ./src/codec_fluidsynth.cpp	2014-01-22 01:32:03.000000000 +0100
@@ -27,6 +27,7 @@
 
 #include <string.h>
 #include <assert.h>
+#include <unistd.h>
 #ifdef _WIN32
 #include <io.h>
 #endif
