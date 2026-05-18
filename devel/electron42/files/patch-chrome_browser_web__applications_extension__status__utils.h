--- chrome/browser/web_applications/extension_status_utils.h.orig	2024-10-16 21:31:04 UTC
+++ chrome/browser/web_applications/extension_status_utils.h
@@ -50,7 +50,7 @@ bool IsExternalExtensionUninstalled(content::BrowserCo
 bool IsExternalExtensionUninstalled(content::BrowserContext* context,
                                     const std::string& extension_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this method returns true, then |extension_id| will not be launchable.
 //
 // The eventual goal is that this method should return true for all hosted apps,
