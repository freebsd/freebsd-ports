--- electron/atom/common/platform_util.h.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/common/platform_util.h
@@ -64,7 +64,7 @@ bool GetLoginItemEnabled();
 bool SetLoginItemEnabled(bool enabled);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
