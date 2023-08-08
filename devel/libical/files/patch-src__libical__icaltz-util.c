--- src/libical/icaltz-util.c.orig	2022-10-17 20:53:57 UTC
+++ src/libical/icaltz-util.c
@@ -82,6 +82,10 @@
 #define bswap_64 __builtin_bswap64
 #endif
 
+#if defined(__FreeBSD__) && !defined(bswap_64)
+#define bswap_64(x) __bswap64(x)
+#endif
+
 typedef struct
 {
     char magic[4];
