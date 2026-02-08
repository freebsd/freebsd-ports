--- electron/shell/common/platform_util.h.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/common/platform_util.h
@@ -60,7 +60,7 @@ bool SetLoginItemEnabled(const std::string& type,
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a desktop name if available.
 // Unlike libgtkui, does *not* use "chromium-browser.desktop" as a fallback.
 std::optional<std::string> GetDesktopName();
