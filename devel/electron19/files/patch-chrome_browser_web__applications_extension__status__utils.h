--- chrome/browser/web_applications/extension_status_utils.h.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -43,7 +43,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
                                     const std::string& extension_id);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Returns whether |extension_id| is a Chrome App and should be blocked by the
 // Chrome Apps Deprecation. Policy installed Chrome Apps are still allowed, and
 // all apps are allowed if the deprecation feature flag is not enabled.
