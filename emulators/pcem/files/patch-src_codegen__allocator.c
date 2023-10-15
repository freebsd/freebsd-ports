--- src/codegen_allocator.c.orig	2020-12-01 19:49:05 UTC
+++ src/codegen_allocator.c
@@ -1,4 +1,4 @@
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdlib.h>
