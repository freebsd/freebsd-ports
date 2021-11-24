--- chrome/browser/search/search_suggest/search_suggest_service.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/search/search_suggest/search_suggest_service.cc
@@ -21,7 +21,11 @@
 #include "components/search/ntp_features.h"
 #include "components/signin/public/identity_manager/accounts_in_cookie_jar_info.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace {
 
