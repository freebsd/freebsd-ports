--- unittests/BCGen/BytecodeFileFormatTest.cpp.orig	2024-08-17 06:22:41 UTC
+++ unittests/BCGen/BytecodeFileFormatTest.cpp
@@ -13,6 +13,7 @@
 
 #include "gtest/gtest.h"
 
+#include <iomanip>
 #include <sstream>
 
 // Structs with bit fields can have different layouts between GCC, CLANG,
