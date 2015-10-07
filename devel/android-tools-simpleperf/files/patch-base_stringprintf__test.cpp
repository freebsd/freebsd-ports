--- base/stringprintf_test.cpp.orig	2015-08-12 23:28:08 UTC
+++ base/stringprintf_test.cpp
@@ -18,6 +18,7 @@
 
 #include <gtest/gtest.h>
 
+#include <errno.h>
 #include <string>
 
 TEST(StringPrintfTest, HexSizeT) {
