--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2024-04-15 20:33:50 UTC
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -111,7 +111,7 @@ BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
              "DesktopPWAsForceUnregisterOSIntegration",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
