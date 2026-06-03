--- chrome/common/controlled_frame/controlled_frame.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/common/controlled_frame/controlled_frame.cc
@@ -18,7 +18,7 @@
 #include "third_party/blink/public/common/features.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -89,7 +89,7 @@ bool AvailabilityCheck(const std::string& api_full_nam
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Verify that the current context is an Isolated Web App and the API name is
   // in our expected list.
   return (extension == nullptr) && url.SchemeIs(webapps::kIsolatedAppScheme) &&
