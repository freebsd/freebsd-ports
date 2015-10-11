--- base/stringprintf_test.cpp.orig	2015-09-17 22:58:36 UTC
+++ base/stringprintf_test.cpp
@@ -18,6 +18,7 @@
 
 #include <gtest/gtest.h>
 
+#include <errno.h>
 #include <string>
 
 TEST(StringPrintfTest, HexSizeT) {
