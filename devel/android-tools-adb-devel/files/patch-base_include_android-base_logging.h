--- base/include/android-base/logging.h.orig	2015-09-29 18:07:07 UTC
+++ base/include/android-base/logging.h
@@ -25,6 +25,8 @@
 #endif
 #endif
 
+#include <errno.h>
+
 #include <functional>
 #include <memory>
 #include <ostream>
