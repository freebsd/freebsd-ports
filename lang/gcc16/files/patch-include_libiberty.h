--- include/libiberty.h.orig	2026-04-30 08:33:28 UTC
+++ include/libiberty.h
@@ -217,7 +217,7 @@ extern int mkstemps(char *, int);
 
 /* Make memrchr available on systems that do not have it.  */
 #if !defined (__GNU_LIBRARY__ ) && !defined (__linux__) && \
-    !defined (HAVE_MEMRCHR)
+    !defined (__FreeBSD__) && !defined (HAVE_MEMRCHR)
 extern void *memrchr(const void *, int, size_t);
 #endif
 
