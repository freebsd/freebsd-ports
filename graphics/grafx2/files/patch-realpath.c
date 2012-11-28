--- ./realpath.c.orig	2012-11-28 11:58:06.000000000 +0100
+++ ./realpath.c	2012-11-28 11:58:22.000000000 +0100
@@ -6,7 +6,7 @@
 #include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
-#if defined(__AROS__) || defined(__linux__) || defined(__GLIBC__)
+#if defined(__AROS__) || defined(__linux__) || defined(__GLIBC__) || defined(__FreeBSD__)
 #include <limits.h>
 #endif
 
