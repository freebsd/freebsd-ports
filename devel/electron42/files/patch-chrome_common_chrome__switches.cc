--- chrome/common/chrome_switches.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/common/chrome_switches.cc
@@ -913,7 +913,7 @@ const char kDebugPrint[] = "debug-print";
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // Causes the browser to launch directly in guest mode.
 const char kGuest[] = "guest";
@@ -957,7 +957,7 @@ const char kGlicGuestUrlPresetProd[] = "glic-guest-url
 const char kGlicGuestUrlPresetPreprod[] = "glic-guest-url-preset-preprod";
 const char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
