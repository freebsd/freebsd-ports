--- types.h.orig	Sat Sep 16 12:32:39 2006
+++ types.h	Sat Sep 16 12:35:48 2006
@@ -35,7 +35,7 @@
     typedef unsigned __int64 u64;
     #define FMT60_020o "%020I64o"
 #elif defined (__GNUC__)
-    #if defined(__alpha__) || defined(__powerpc64__) || (defined(__sparc64__) && defined(__arch64__))
+    #if defined(__alpha__) || defined(__amd64__) || defined(__ia64__) || defined(__powerpc64__) || (defined(__sparc64__) && defined(__arch64__))
         /*
         **  64 bit systems
         */
