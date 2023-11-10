--- src/codegen_x86-64.c.orig	2020-12-01 19:49:05 UTC
+++ src/codegen_x86-64.c
@@ -15,7 +15,7 @@
 #include "codegen_ops.h"
 #include "codegen_ops_x86-64.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
