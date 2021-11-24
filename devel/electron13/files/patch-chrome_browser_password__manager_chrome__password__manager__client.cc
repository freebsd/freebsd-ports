--- chrome/browser/password_manager/chrome_password_manager_client.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/password_manager/chrome_password_manager_client.cc
@@ -9,6 +9,10 @@
 #include <string>
 #include <utility>
 
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#endif
+
 #include "base/bind.h"
 #include "base/callback_helpers.h"
 #include "base/command_line.h"
@@ -102,8 +106,11 @@
 #include "net/cert/cert_status_flags.h"
 #include "services/metrics/public/cpp/ukm_recorder.h"
 #include "services/network/public/cpp/is_potentially_trustworthy.h"
-#include "third_party/re2/src/re2/re2.h"
 #include "url/url_constants.h"
+
+#if !defined(OS_BSD)
+#include "third_party/re2/src/re2/re2.h"
+#endif
 
 #if BUILDFLAG(FULL_SAFE_BROWSING)
 #include "chrome/browser/safe_browsing/advanced_protection_status_manager.h"
