--- src/vesta.c.orig	2020-03-19 05:46:20 UTC
+++ src/vesta.c
@@ -82,7 +82,7 @@
 
 #define LIB_LINE_MAX  65535
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 // Linux defines a comparison function prototype, the Mac doesn't. . .
 typedef int (*__compar_fn_t)(const void *, const void *);
 #endif
