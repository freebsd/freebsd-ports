--- extensions/browser/api/declarative_webrequest/webrequest_action.cc.orig	2019-12-12 12:39:43 UTC
+++ extensions/browser/api/declarative_webrequest/webrequest_action.cc
@@ -27,7 +27,11 @@
 #include "extensions/common/extension.h"
 #include "net/base/registry_controlled_domains/registry_controlled_domain.h"
 #include "net/http/http_util.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using extension_web_request_api_helpers::EventResponseDelta;
 
