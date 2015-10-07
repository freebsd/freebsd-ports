--- adb/fdevent_test.cpp.orig	2015-09-17 22:58:36 UTC
+++ adb/fdevent_test.cpp
@@ -19,6 +19,7 @@
 #include <gtest/gtest.h>
 
 #include <limits>
+#include <memory> // std::unique_ptr
 #include <queue>
 #include <string>
 #include <vector>
