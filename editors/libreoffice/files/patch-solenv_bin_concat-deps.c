--- solenv/bin/concat-deps.c.orig	2015-08-22 06:41:35 UTC
+++ solenv/bin/concat-deps.c
@@ -33,9 +33,7 @@
 #define CORE_LITTLE_ENDIAN
 #endif /* Def _MSC_VER */
 
-#if defined(__linux) || defined(__OpenBSD__) || \
-    defined(__FreeBSD__) || defined(__NetBSD__) || \
-    defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#if defined(__linux) || defined(__FreeBSD_kernel__)
 #include <sys/param.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #undef CORE_BIG_ENDIAN
@@ -46,7 +44,21 @@
 #undef CORE_LITTLE_ENDIAN
 #endif /* __BYTE_ORDER == __BIG_ENDIAN */
 #endif /* !(__BYTE_ORDER == __LITTLE_ENDIAN) */
-#endif /* Def __linux || Def *BSD */
+#endif /* Def __linux */
+
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__DragonFly__)
+#include <machine/endian.h>
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#undef CORE_BIG_ENDIAN
+#define CORE_LITTLE_ENDIAN
+#else /* !(_BYTE_ORDER == _LITTLE_ENDIAN) */
+#if _BYTE_ORDER == _BIG_ENDIAN
+#define CORE_BIG_ENDIAN
+#undef CORE_LITTLE_ENDIAN
+#endif /* _BYTE_ORDER == _BIG_ENDIAN */
+#endif /* !(_BYTE_ORDER == _LITTLE_ENDIAN) */
+#endif /* Def *BSD */
 
 #ifdef __sun
 #ifdef __sparc
