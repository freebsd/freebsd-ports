--- electron/brightray/common/platform_util.h.orig	2019-03-16 12:07:20 UTC
+++ electron/brightray/common/platform_util.h
@@ -11,7 +11,7 @@ namespace brightray {
 
 namespace platform_util {
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
