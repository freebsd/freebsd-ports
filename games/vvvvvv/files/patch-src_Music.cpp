--- src/Music.cpp.orig	2024-01-10 16:27:34 UTC
+++ src/Music.cpp
@@ -69,13 +69,24 @@
 #define fread(dst, size, count, io) SDL_RWread(io, dst, size, count)
 #define fseek(io, offset, whence) SDL_RWseek(io, offset, whence)
 #define ftell(io) SDL_RWtell(io)
+#define fgetc(stream) VVVVVV_fgetc(stream)
 
+static int VVVVVV_fgetc(SDL_RWops *stream)
+{
+    size_t n;
+    unsigned char buf;
+
+    n = stream->read(stream, &buf, 1, 1);
+
+    return (n == 1 ? buf : -1);
+}
+
 #define FAudio_alloca(x) SDL_stack_alloc(uint8_t, x)
 #define FAudio_dealloca(x) SDL_stack_free(x)
 
 #define STB_VORBIS_NO_PUSHDATA_API 1
 #define STB_VORBIS_NO_INTEGER_CONVERSION 1
-#include <stb_vorbis.h>
+#include <stb/stb_vorbis.c>
 
 /* End stb_vorbis include */
 
