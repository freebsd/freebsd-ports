--- realpath.c.orig	2012-08-05 13:18:08 UTC
+++ realpath.c
@@ -6,7 +6,7 @@
 #include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
-#if defined(__AROS__) || defined(__linux__) || defined(__GLIBC__)
+#if defined(__AROS__) || defined(__linux__) || defined(__GLIBC__) || defined(__FreeBSD__)
 #include <limits.h>
 #endif
 
