-- patch to fix tests and maybe run-time failures

--- reproc/src/process.posix.c.orig	2026-08-28 12:05:59 UTC
+++ reproc/src/process.posix.c
@@ -1,5 +1,7 @@
 #define _POSIX_C_SOURCE 200809L
+#include <pthread.h>
 
+
 #include "process.h"
 
 #include <dirent.h>
@@ -13,6 +15,8 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+
+#include <sys/stat.h>
 
 #include "error.h"
 #include "macro.h"
