-- patch to fix tests and maybe run-time failures

--- reproc/src/process.posix.c	2026-04-15 03:47:51.000000000 -0700
+++ reproc/src/process.posix.c	2026-04-15 23:44:29.815332000 -0700
@@ -1,4 +1,6 @@
 #define _POSIX_C_SOURCE 200809L
+#include <pthread.h>
+
 
 #include "process.h"
 
@@ -100,7 +102,7 @@
   return cwd;
 }
 
-static const int MAX_FD_LIMIT = 1024 * 1024;
+static const int MAX_FD_LIMIT = 1024 * 1024 * 2;
 
 static int get_max_fd(void)
 {
