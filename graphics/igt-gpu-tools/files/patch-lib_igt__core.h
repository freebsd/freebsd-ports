--- lib/igt_core.h.orig	2022-08-30 07:06:59 UTC
+++ lib/igt_core.h
@@ -31,7 +31,11 @@
 #define IGT_CORE_H
 
 #include <assert.h>
+#ifdef __linux__
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
 #include <setjmp.h>
 #include <stdbool.h>
 #include <stdint.h>
@@ -47,6 +51,10 @@
 #define IGT_LOG_DOMAIN (NULL)
 #endif
 
+#ifdef __FreeBSD__
+#include <signal.h>
+#define	jmp_buf	sigjmp_buf
+#endif
 
 #ifndef STATIC_ANALYSIS_BUILD
 #if defined(__clang_analyzer__) || defined(__COVERITY__) || defined(__KLOCWORK__)
@@ -1449,8 +1457,8 @@ void igt_kmsg(const char *format, ...);
 #define WRITE_ONCE(x, v) do *(volatile typeof(x) *)(&(x)) = (v); while (0)
 
 #if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
-#define cpu_to_le32(x)  bswap_32(x)
-#define le32_to_cpu(x)  bswap_32(x)
+#define cpu_to_le32(x)  bswap32(x)
+#define le32_to_cpu(x)  bswap32(x)
 #else
 #define cpu_to_le32(x)  (x)
 #define le32_to_cpu(x)  (x)
