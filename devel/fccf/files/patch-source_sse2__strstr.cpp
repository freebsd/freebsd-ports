--- source/sse2_strstr.cpp.orig	2022-08-27 09:05:40 UTC
+++ source/sse2_strstr.cpp
@@ -2,7 +2,9 @@
 #include <cstring>
 
 #include <ctype.h>
+#if defined(__x86_64__) || defined (__i386__)
 #include <immintrin.h>
+#endif
 #include <sse2_strstr.hpp>
 
 #define FORCE_INLINE inline __attribute__((always_inline))
