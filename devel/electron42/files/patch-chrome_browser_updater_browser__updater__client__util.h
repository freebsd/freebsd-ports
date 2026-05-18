--- chrome/browser/updater/browser_updater_client_util.h.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/updater/browser_updater_client_util.h
@@ -20,7 +20,7 @@ extern const char kPrivilegedHelperName[];
 extern const char kUpdaterName[];
 extern const char kPrivilegedHelperName[];
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 // System level updater should only be used if the browser is owned by root.
 // During promotion, the browser will be changed to be owned by root and wheel.
