--- base/file.cpp.orig	2016-08-08 21:10:17 UTC
+++ base/file.cpp
@@ -21,6 +21,8 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
+#include <cstdio> // BUFSIZ
+#include <cstring> // strerror
 #include <string>
 
 #include "android-base/macros.h"  // For TEMP_FAILURE_RETRY on Darwin.
