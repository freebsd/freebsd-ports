--- base/errors_unix.cpp.orig	2016-02-20 02:39:51 UTC
+++ base/errors_unix.cpp
@@ -16,7 +16,7 @@
 
 #include "android-base/errors.h"
 
-#include <errno.h>
+#include <string.h>
 
 namespace android {
 namespace base {
