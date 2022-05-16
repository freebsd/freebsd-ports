--- electron/shell/common/platform_util.h.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/common/platform_util.h
@@ -52,7 +52,7 @@ bool GetLoginItemEnabled();
 bool SetLoginItemEnabled(bool enabled);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
