--- chrome/browser/web_applications/extension_status_utils.h.orig	2023-02-01 18:43:13 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -48,7 +48,7 @@ bool ClearExternalExtensionUninstalled(content::Browse
                                        const std::string& extension_id);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Returns whether |extension_id| is a Chrome App and should be blocked by the
 // Chrome Apps Deprecation. Policy installed Chrome Apps are still allowed, and
 // all apps are allowed if the deprecation feature flag is not enabled.
