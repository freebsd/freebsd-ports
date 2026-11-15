--- electron/shell/browser/api/electron_api_menu_roles.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_menu_roles.cc
@@ -43,7 +43,7 @@ constexpr bool kIsWin = false;
 #else
 constexpr bool kIsWin = false;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr bool kIsLinux = true;
 #else
 constexpr bool kIsLinux = false;
