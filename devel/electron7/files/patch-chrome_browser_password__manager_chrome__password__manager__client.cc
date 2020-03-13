--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2019-12-12 12:39:11 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -84,7 +84,11 @@
 #include "net/base/url_util.h"
 #include "net/cert/cert_status_flags.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/url_constants.h"
 
 #if BUILDFLAG(FULL_SAFE_BROWSING)
