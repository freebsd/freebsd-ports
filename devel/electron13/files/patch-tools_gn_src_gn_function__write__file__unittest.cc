--- tools/gn/src/gn/function_write_file_unittest.cc.orig	2021-01-07 00:45:48 UTC
+++ tools/gn/src/gn/function_write_file_unittest.cc
@@ -13,7 +13,7 @@
 #include "gn/test_with_scope.h"
 #include "util/test/test.h"
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_HAIKU) || defined(OS_MSYS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_HAIKU) || defined(OS_MSYS) || defined(OS_BSD)
 #include <sys/time.h>
 #endif
 
