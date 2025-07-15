--- chrome/browser/devtools/features.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/devtools/features.cc
@@ -164,7 +164,7 @@ BASE_FEATURE(kDevToolsNewPermissionDialog,
              "DevToolsNewPermissionDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, DevTools does not accept remote debugging connections unless
 // using a non-default user data dir via the --user-data-dir switch.
 BASE_FEATURE(kDevToolsDebuggingRestrictions,
