--- chrome/browser/apps/platform_apps/platform_app_launch.h.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/apps/platform_apps/platform_app_launch.h
@@ -36,7 +36,7 @@ bool OpenExtensionApplicationWindow(Profile* profile,
 // and false otherwise.
 bool OpenExtensionApplicationTab(Profile* profile, const std::string& app_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Opens the deprecated Chrome Apps flow if |app_id| refers to a Chrome App and
 // Chrome Apps are deprecated on the |profile|. Returns true if that was the
 // case, or false otherwise.
