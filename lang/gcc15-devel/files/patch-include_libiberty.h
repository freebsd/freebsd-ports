--- include/libiberty.h.orig	2025-08-08 06:51:44 UTC
+++ include/libiberty.h
@@ -221,7 +221,7 @@ extern int mkstemps(char *, int);
 
 /* Make memrchr available on systems that do not have it.  */
 #if !defined (__GNU_LIBRARY__ ) && !defined (__linux__) && \
-    !defined (HAVE_MEMRCHR)
+    !defined (__FreeBSD__) && !defined (HAVE_MEMRCHR)
 extern void *memrchr(const void *, int, size_t);
 #endif
 
