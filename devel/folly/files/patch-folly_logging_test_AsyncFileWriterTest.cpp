- workaround for https://github.com/facebook/folly/issues/1866

--- folly/logging/test/AsyncFileWriterTest.cpp.orig	2022-11-25 05:13:23 UTC
+++ folly/logging/test/AsyncFileWriterTest.cpp
@@ -45,6 +45,8 @@
 #include <folly/system/ThreadName.h>
 #include <folly/test/TestUtils.h>
 
+#include <sys/wait.h>
+
 DEFINE_int64(
     async_discard_num_normal_writers,
     30,
