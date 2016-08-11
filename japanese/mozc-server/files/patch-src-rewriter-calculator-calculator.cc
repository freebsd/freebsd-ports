--- src/rewriter/calculator/calculator.cc.orig	2016-03-13 11:22:55.000000000 +0900
+++ src/rewriter/calculator/calculator.cc	2016-05-24 02:06:47.310077000 +0900
@@ -44,6 +44,9 @@
 #include <map>
 #include <string>
 #include <vector>
+#if defined(__GNUC__) && !defined(__clang__)
+#include <cstdlib>
+#endif
 
 #include "base/compiler_specific.h"
 #include "base/logging.h"
