--- base/logging_test.cpp.orig	2015-09-17 22:58:36 UTC
+++ base/logging_test.cpp
@@ -16,6 +16,7 @@
 
 #include "base/logging.h"
 
+#include <errno.h>
 #include <libgen.h>
 
 #include <regex>
