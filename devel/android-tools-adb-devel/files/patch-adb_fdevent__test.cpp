--- adb/fdevent_test.cpp.orig	2015-09-05 00:01:27 UTC
+++ adb/fdevent_test.cpp
@@ -18,6 +18,7 @@
 
 #include <gtest/gtest.h>
 
+#include <memory> // std::unique_ptr
 #include <queue>
 #include <string>
 #include <vector>
