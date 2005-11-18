--- src/icecpp/config.h.orig	Thu Sep 22 18:01:13 2005
+++ src/icecpp/config.h	Thu Nov 17 10:50:07 2005
@@ -72,7 +72,8 @@
 #if defined(_WIN32)
 #   define WCHAR_TYPE_SIZE 2
 #elif (defined(__linux) || defined(__FreeBSD__)) && \
-      (defined(__i386) || defined(__x86_64) || defined(__sparc)) || \
+      (defined(__i386) || defined(__x86_64) || defined(__sparc) || \
+       defined(__alpha__) || defined(__powerpc__)) || \
        defined (__sun) || defined(__hpux) || defined(__APPLE__) || \
        defined(_AIX) || defined(__osf1__)
 #   define WCHAR_TYPE_SIZE 4
