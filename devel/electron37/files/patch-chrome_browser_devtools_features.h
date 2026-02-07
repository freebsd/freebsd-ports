--- chrome/browser/devtools/features.h.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/devtools/features.h
@@ -92,7 +92,7 @@ BASE_DECLARE_FEATURE(kDevToolsNewPermissionDialog);
 
 BASE_DECLARE_FEATURE(kDevToolsNewPermissionDialog);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDevToolsDebuggingRestrictions);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
