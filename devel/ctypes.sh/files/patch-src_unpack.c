--- src/unpack.c.orig	2022-07-19 16:33:30 UTC
+++ src/unpack.c
@@ -22,7 +22,7 @@
 #include "types.h"
 #include "shell.h"
 
-#if !defined(__GLIBC__) && !defined(__NEWLIB__)
+#if !defined(HAVE_MEMPCPY)
 static inline void *mempcpy(void *dest, const void *src, size_t n)
 {
     memcpy(dest, src, n);
