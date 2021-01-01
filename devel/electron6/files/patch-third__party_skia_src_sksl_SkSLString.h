--- third_party/skia/src/sksl/SkSLString.h.orig	2019-09-10 11:16:50 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -22,6 +22,8 @@
     #include "include/core/SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
