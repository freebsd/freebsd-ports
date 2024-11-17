- workaround for https://github.com/facebook/folly/pull/2338#issuecomment-2481533535

--- folly/system/EnvUtil.cpp.orig	2024-11-17 20:11:35 UTC
+++ folly/system/EnvUtil.cpp
@@ -22,6 +22,8 @@
 #include <folly/portability/Stdlib.h>
 #include <folly/portability/Unistd.h>
 
+#include <stdlib.h>
+
 using namespace folly;
 using namespace folly::experimental;
 
