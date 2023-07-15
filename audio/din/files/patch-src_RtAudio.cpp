Add support for compiling in ISO C++17
--- src/RtAudio.cpp.orig	2023-07-15 17:18:23 UTC
+++ src/RtAudio.cpp
@@ -10050,8 +10050,13 @@ void RtApi :: byteSwapBuffer( char *buffer, unsigned i
 
 void RtApi :: byteSwapBuffer( char *buffer, unsigned int samples, RtAudioFormat format )
 {
+  #if __cplusplus < 201703L
   register char val;
   register char *ptr;
+  #else
+  char val;
+  char *ptr;
+  #endif
 
   ptr = buffer;
   if ( format == RTAUDIO_SINT16 ) {
