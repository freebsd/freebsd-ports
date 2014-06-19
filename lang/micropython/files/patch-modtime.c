--- modtime.c.orig	2014-06-05 20:07:38.000000000 +0200
+++ modtime.c	2014-06-06 07:58:58.000000000 +0200
@@ -59,6 +59,8 @@
 #define CLOCK_DIV 1000.0
 #elif defined(MP_CLOCKS_PER_SEC) && (MP_CLOCKS_PER_SEC == 1000) // WIN32
 #define CLOCK_DIV 1.0
+#elif defined(__FreeBSD__) && (MP_CLOCKS_PER_SEC == 128)
+#define CLOCK_DIV (1.0 / 128.0)
 #else
 #error Unsupported clock() implementation
 #endif
