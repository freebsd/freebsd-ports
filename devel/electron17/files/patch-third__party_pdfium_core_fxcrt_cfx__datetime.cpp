--- third_party/pdfium/core/fxcrt/cfx_datetime.cpp.orig	2022-05-11 07:17:49 UTC
+++ third_party/pdfium/core/fxcrt/cfx_datetime.cpp
@@ -11,7 +11,7 @@
 #include "third_party/base/check.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_APPLE) || defined(OS_ASMJS)
+    defined(OS_APPLE) || defined(OS_ASMJS) || defined(OS_BSD)
 #include <sys/time.h>
 #include <time.h>
 #endif
