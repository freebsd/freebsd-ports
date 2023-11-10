--- src/codegen_backend_x86.c.orig	2020-12-01 19:49:05 UTC
+++ src/codegen_backend_x86.c
@@ -11,7 +11,7 @@
 #include "codegen_reg.h"
 #include "x86.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
