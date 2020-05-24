--- third_party/skia/src/sksl/SkSLString.h.orig	2019-04-08 08:24:21 UTC
+++ third_party/skia/src/sksl/SkSLString.h
@@ -22,6 +22,8 @@
     #include "SkString.h"
 #endif
 
+#include <stdarg.h>
+
 namespace SkSL {
 
 // Represents a (not necessarily null-terminated) slice of a string.
