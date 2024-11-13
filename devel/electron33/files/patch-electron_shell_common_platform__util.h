--- electron/shell/common/platform_util.h.orig	2024-02-21 16:26:48 UTC
+++ electron/shell/common/platform_util.h
@@ -56,7 +56,7 @@ bool SetLoginItemEnabled(const std::string& type,
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a success flag.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 bool GetDesktopName(std::string* setme);
