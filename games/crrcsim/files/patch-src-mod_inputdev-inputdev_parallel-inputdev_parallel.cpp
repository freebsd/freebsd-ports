--- src/mod_inputdev/inputdev_parallel/inputdev_parallel.cpp.orig	2009-03-07 19:41:23.000000000 +0300
+++ src/mod_inputdev/inputdev_parallel/inputdev_parallel.cpp	2009-03-12 01:47:06.000000000 +0300
@@ -28,7 +28,7 @@
 #if defined(__APPLE__) || defined(MACOSX)
 #else
 #  if defined(WIN32)
-#  elif defined(__powerpc__)
+#  elif defined(__powerpc__) || defined (__FreeBSD__)
 #    define ioperm(a,b,c) -1
 #    define inb(a) 0
 #    define outb(a,b)
