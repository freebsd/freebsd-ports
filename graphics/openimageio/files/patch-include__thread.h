--- include/thread.h.orig	2013-03-01 21:46:47.380515836 +1030
+++ include/thread.h	2013-03-01 21:46:56.456181119 +1030
@@ -110,9 +110,7 @@
 #endif
 
 #if defined(__GNUC__) && (defined(_GLIBCXX_ATOMIC_BUILTINS) || (__GNUC__ * 100 + __GNUC_MINOR__ >= 401))
-#if !defined(__FreeBSD__) || defined(__x86_64__)
 #define USE_GCC_ATOMICS
-#endif
 #endif
 
 OIIO_NAMESPACE_ENTER
