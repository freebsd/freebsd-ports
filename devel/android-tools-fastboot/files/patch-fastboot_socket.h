--- fastboot/socket.h.orig	2016-02-20 02:39:51 UTC
+++ fastboot/socket.h
@@ -41,7 +41,10 @@
 
 #include <android-base/macros.h>
 #include <cutils/sockets.h>
-#include <gtest/gtest_prod.h>
+
+// Copied from <gtest/gtest_prod.h>
+#define FRIEND_TEST(test_case_name, test_name)\
+friend class test_case_name##_##test_name##_Test
 
 // Socket interface to be implemented for each platform.
 class Socket {
