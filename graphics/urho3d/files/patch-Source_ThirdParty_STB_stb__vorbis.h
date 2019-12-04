--- Source/ThirdParty/STB/stb_vorbis.h.orig	2019-06-18 23:14:07 UTC
+++ Source/ThirdParty/STB/stb_vorbis.h
@@ -554,7 +554,6 @@ enum STBVorbisError
 #include <assert.h>
 #include <math.h>
 #if !(defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh))
-#include <malloc.h>
 #if defined(__linux__) || defined(__linux) || defined(__EMSCRIPTEN__)
 #include <alloca.h>
 #endif
