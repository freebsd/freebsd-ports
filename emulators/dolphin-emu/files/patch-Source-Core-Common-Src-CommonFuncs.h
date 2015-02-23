--- Source/Core/Common/Src/CommonFuncs.h.orig	2015-02-23 09:00:42.000000000 +0100
+++ Source/Core/Common/Src/CommonFuncs.h	2015-02-23 10:04:34.000000000 +0100
@@ -12,6 +12,11 @@
 #define SLEEP(x) usleep(x*1000)
 #endif
 
+#if defined __FreeBSD__
+#include <sys/cdefs.h>
+#define __GNUC_PREREQ __GNUC_PREREQ__
+#endif
+
 #include <cstddef>
 #include <type_traits>
 
@@ -30,7 +35,8 @@
 #define b32(x)  (b16(x) | (b16(x) >>16) )
 #define ROUND_UP_POW2(x)	(b32(x - 1) + 1)
 
-#if defined __GNUC__ && !defined __SSSE3__ && !defined _M_GENERIC
+#if (defined __GNUC__ && !__GNUC_PREREQ(4,9)) && \
+    !defined __SSSE3__ && defined _M_X86
 #include <emmintrin.h>
 static __inline __m128i __attribute__((__always_inline__))
 _mm_shuffle_epi8(__m128i a, __m128i mask)
