--- base/process/internal_linux.h.orig	2019-09-10 10:42:27 UTC
+++ base/process/internal_linux.h
@@ -14,6 +14,8 @@
 
 #include "base/files/file_path.h"
 
+#include <unistd.h> /* pid_t */
+
 namespace base {
 
 class Time;
