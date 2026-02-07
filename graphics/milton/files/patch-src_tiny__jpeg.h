--- src/tiny_jpeg.h.orig	2019-03-15 04:11:43 UTC
+++ src/tiny_jpeg.h
@@ -217,7 +217,7 @@ static uint8_t tjei_g_output_buffer[TJEI_BUFFER_SIZE];
 
 #ifdef _WIN32
 #define tje_log(msg) OutputDebugStringA(msg)
-#elif defined(__linux__) || defined(__MACH__)
+#elif defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
 #define tje_log(msg) puts(msg)
 #endif
 
