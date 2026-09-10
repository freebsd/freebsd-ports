--- chrome/common/chrome_switches.h.orig	2026-08-24 20:59:34 UTC
+++ chrome/common/chrome_switches.h
@@ -288,7 +288,7 @@ extern const char kDebugPrint[];
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kGuest[];
 #endif
 
@@ -311,7 +311,7 @@ extern const char kGlicGuestUrlPresetProd[];
 extern const char kGlicGuestUrlPresetPreprod[];
 extern const char kGlicGuestUrlPresetProd[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kListApps[];
 extern const char kProfileBaseName[];
 extern const char kProfileManagementAttributes[];
