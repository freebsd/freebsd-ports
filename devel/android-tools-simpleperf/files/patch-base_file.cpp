--- base/file.cpp.orig	2015-08-12 23:28:08 UTC
+++ base/file.cpp
@@ -21,6 +21,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
+#include <cstring> // strerror
 #include <string>
 
 #include "base/macros.h"  // For TEMP_FAILURE_RETRY on Darwin.
