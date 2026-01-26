--- src/s3fs.cpp.orig   2026-01-26 04:28:46 UTC
+++ src/s3fs.cpp
@@ -32,6 +32,7 @@
 #include <dirent.h>  // NOLINT(misc-include-cleaner)
 #include <sys/types.h>
 #include <getopt.h>  // NOLINT(misc-include-cleaner)
+#include <sys/wait.h> // WEXITSTATUS
 
 #include "common.h"
 #include "s3fs.h"  // NOLINT(misc-include-cleaner)
