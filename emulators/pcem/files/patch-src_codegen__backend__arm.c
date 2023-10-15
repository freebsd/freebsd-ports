--- src/codegen_backend_arm.c.orig	2020-12-01 19:49:05 UTC
+++ src/codegen_backend_arm.c
@@ -11,7 +11,7 @@
 #include "x86.h"
 #include "x87.h"
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
