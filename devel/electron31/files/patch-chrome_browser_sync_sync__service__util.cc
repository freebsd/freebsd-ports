--- chrome/browser/sync/sync_service_util.cc.orig	2024-06-18 21:43:24 UTC
+++ chrome/browser/sync/sync_service_util.cc
@@ -9,7 +9,7 @@
 #include "components/sync/base/features.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "components/variations/service/variations_service.h"
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||
         // BUILDFLAG(IS_WIN)
@@ -21,7 +21,7 @@ bool IsDesktopEnUSLocaleOnlySyncPollFeatureEnabled() {
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::string country_code;
   auto* variations_service = g_browser_process->variations_service();
   if (variations_service) {
