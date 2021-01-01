--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -76,7 +76,11 @@
 #include "net/base/url_util.h"
 #include "net/cert/cert_status_flags.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/url_constants.h"
 
 #if defined(SAFE_BROWSING_DB_LOCAL)
