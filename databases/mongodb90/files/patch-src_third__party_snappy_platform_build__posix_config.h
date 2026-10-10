--- src/third_party/snappy/platform/build_posix/config.h.orig
+++ src/third_party/snappy/platform/build_posix/config.h
@@ -44,7 +44,7 @@
 #define HAVE_WINDOWS_H 0
 
 /* Define to 1 if you target processors with SSSE3+ and have <tmmintrin.h>. */
-#define SNAPPY_HAVE_SSSE3 1
+#define SNAPPY_HAVE_SSSE3 0
 
 /* Define to 1 if you target processors with SSE4.2 and have <crc32intrin.h>. */
 #define SNAPPY_HAVE_X86_CRC32 0
