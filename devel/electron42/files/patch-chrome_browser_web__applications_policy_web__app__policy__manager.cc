--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -124,7 +124,7 @@ BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
 namespace web_app {
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
