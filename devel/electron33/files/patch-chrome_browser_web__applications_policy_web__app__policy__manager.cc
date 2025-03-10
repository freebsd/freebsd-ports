--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2024-10-16 21:31:04 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -102,7 +102,7 @@ BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
              "DesktopPWAsForceUnregisterOSIntegration",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
