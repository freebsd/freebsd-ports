--- base/include/base/logging.h.orig	2015-08-12 23:28:08 UTC
+++ base/include/base/logging.h
@@ -25,6 +25,7 @@
 #endif
 #endif
 
+#include <cerrno> // errno
 #include <functional>
 #include <memory>
 #include <ostream>
