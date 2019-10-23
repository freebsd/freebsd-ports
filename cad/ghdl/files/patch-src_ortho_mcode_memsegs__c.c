--- src/ortho/mcode/memsegs_c.c.orig	2019-10-23 03:42:40 UTC
+++ src/ortho/mcode/memsegs_c.c
@@ -28,7 +28,7 @@
    set rights.
 */
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define MAP_ANONYMOUS MAP_ANON
 #else
 #define HAVE_MREMAP
