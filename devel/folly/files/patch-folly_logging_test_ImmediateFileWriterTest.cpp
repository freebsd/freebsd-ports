- workaround for https://github.com/facebook/folly/issues/1865

--- folly/logging/test/ImmediateFileWriterTest.cpp.orig	2022-11-25 05:13:23 UTC
+++ folly/logging/test/ImmediateFileWriterTest.cpp
@@ -30,6 +30,8 @@
 #include <folly/portability/GMock.h>
 #include <folly/portability/GTest.h>
 
+#include <signal.h>
+
 using namespace folly;
 using folly::test::TemporaryFile;
 
