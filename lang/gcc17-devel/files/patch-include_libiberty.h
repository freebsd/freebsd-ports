--- include/libiberty.h.orig	2026-07-27 02:16:18 UTC
+++ include/libiberty.h
@@ -222,7 +222,7 @@ extern int mkstemps(char *, int);
 
 /* Make memrchr available on systems that do not have it.  */
 #if !defined (__GNU_LIBRARY__ ) && !defined (__linux__) && \
-    !defined (HAVE_MEMRCHR)
+    !defined (__FreeBSD__) && !defined (HAVE_MEMRCHR)
 extern void *memrchr(const void *, int, size_t);
 #endif
 
