--- electron/shell/common/platform_util.h.orig	2025-07-02 10:12:01 UTC
+++ electron/shell/common/platform_util.h
@@ -57,7 +57,7 @@ bool SetLoginItemEnabled(const std::string& type,
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a desktop name if available.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 std::optional<std::string> GetDesktopName();
