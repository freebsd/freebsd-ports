--- src/icecpp/config.h.orig	Wed Feb 16 21:22:23 2005
+++ src/icecpp/config.h	Wed Jun  8 12:28:58 2005
@@ -56,7 +56,7 @@
 #define LONG_TYPE_SIZE 4
 #if defined(_WIN32)
 #   define WCHAR_TYPE_SIZE 2
-#elif (defined(__linux) || defined(__FreeBSD__)) && (defined(__i386) || defined(__x86_64) || defined(__sparc)) \
+#elif (defined(__linux) || defined(__FreeBSD__)) && (defined(__i386) || defined(__x86_64) || defined(__sparc) || defined(__alpha__) || defined(__powerpc__) \
       || defined (__sun) || defined(__hpux) || defined(__APPLE__) || defined(_AIX)
 #   define WCHAR_TYPE_SIZE 4
 #else
