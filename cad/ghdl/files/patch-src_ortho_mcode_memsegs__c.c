--- src/ortho/mcode/memsegs_c.c.orig	2026-03-07 17:47:40 UTC
+++ src/ortho/mcode/memsegs_c.c
@@ -26,7 +26,7 @@
    set rights.
 */
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define MAP_ANONYMOUS MAP_ANON
 #elif defined(__NetBSD__)
 /* none */
