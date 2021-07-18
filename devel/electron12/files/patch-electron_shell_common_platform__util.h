--- electron/shell/common/platform_util.h.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/common/platform_util.h
@@ -59,7 +59,7 @@ bool GetLoginItemEnabled();
 bool SetLoginItemEnabled(bool enabled);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
