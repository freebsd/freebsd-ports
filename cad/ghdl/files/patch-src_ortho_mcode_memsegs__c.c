--- src/ortho/mcode/memsegs_c.c.orig	2022-02-28 18:46:53 UTC
+++ src/ortho/mcode/memsegs_c.c
@@ -26,7 +26,7 @@
    set rights.
 */
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define MAP_ANONYMOUS MAP_ANON
 #else
 #define HAVE_MREMAP
