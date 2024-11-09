--- test/animationinfo_test.cpp.orig	2024-08-30 02:34:25 UTC
+++ test/animationinfo_test.cpp
@@ -3,6 +3,8 @@
 #include "engine/animationinfo.h"
 #include "nthread.h"
 
+#include <iomanip>
+
 using namespace devilution;
 
 enum class TestDataType {
