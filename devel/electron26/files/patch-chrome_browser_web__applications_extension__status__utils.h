--- chrome/browser/web_applications/extension_status_utils.h.orig	2023-05-25 00:41:46 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -56,7 +56,7 @@ bool ClearExternalExtensionUninstalled(content::Browse
                                        const std::string& extension_id);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Returns whether |extension_id| is a Chrome App and should be blocked by the
 // Chrome Apps Deprecation. Policy installed Chrome Apps are still allowed, and
 // all apps are allowed if the deprecation feature flag is not enabled.
