--- components/feedback/anonymizer_tool.cc.orig	2019-12-12 12:39:30 UTC
+++ components/feedback/anonymizer_tool.cc
@@ -14,7 +14,11 @@
 #include "base/strings/stringprintf.h"
 #include "content/public/browser/browser_thread.h"
 #include "net/base/ip_address.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using re2::RE2;
 
