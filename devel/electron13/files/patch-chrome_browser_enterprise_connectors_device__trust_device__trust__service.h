--- chrome/browser/enterprise/connectors/device_trust/device_trust_service.h.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/enterprise/connectors/device_trust/device_trust_service.h
@@ -16,9 +16,9 @@
 
 #include <memory>
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/device_trust_key_pair.h"
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
 class KeyedService;
 class Profile;
@@ -59,9 +59,9 @@ class DeviceTrustService : public KeyedService {
 
   PrefService* prefs_;
 
-#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
   std::unique_ptr<DeviceTrustKeyPair> key_pair_;
-#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD)
 
   PrefChangeRegistrar pref_observer_;
   bool first_report_sent_;
