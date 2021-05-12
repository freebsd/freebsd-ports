--- third_party/skia/src/sksl/SkSLString.h.orig	2021-04-14 01:15:29 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -17,6 +17,8 @@
 #include "include/core/SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 class String;
