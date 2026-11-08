--- mysqlshdk/libs/utils/logger.cc.orig	2026-01-26 16:59:21 UTC
+++ mysqlshdk/libs/utils/logger.cc
@@ -38,6 +38,7 @@
 #include <processthreadsapi.h>
 #else  // !_WIN32
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <unistd.h>
