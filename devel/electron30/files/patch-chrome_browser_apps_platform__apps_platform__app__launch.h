--- chrome/browser/apps/platform_apps/platform_app_launch.h.orig	2024-04-15 20:33:45 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.h
@@ -39,7 +39,7 @@ content::WebContents* OpenExtensionApplicationTab(Prof
                                                   const std::string& app_id);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 // Opens the deprecated Chrome Apps flow if |app_id| refers to a Chrome App and
 // Chrome Apps are deprecated on the |profile|. Returns true if that was the
 // case, or false otherwise.
