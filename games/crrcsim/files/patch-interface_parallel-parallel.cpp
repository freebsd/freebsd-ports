--- interface_parallel/parallel.cpp.orig	2008-04-30 00:00:35.000000000 +0400
+++ interface_parallel/parallel.cpp	2008-06-17 03:49:23.000000000 +0400
@@ -5,7 +5,7 @@
 #if defined(__APPLE__) || defined(MACOSX)
 #else
 #  if defined(WIN32)
-#  elif defined(__powerpc__)
+#  elif defined(__powerpc__) || defined(__FreeBSD__)
 #    define ioperm(a,b,c) -1
 #    define inb(a) 0
 #    define outb(a,b)
