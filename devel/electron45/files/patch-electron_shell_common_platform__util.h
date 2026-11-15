--- electron/shell/common/platform_util.h.orig	2026-03-17 08:46:52 UTC
+++ electron/shell/common/platform_util.h
@@ -60,7 +60,7 @@ bool SetLoginItemEnabled(const std::string& type,
                          bool enabled);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns a desktop name (e.g. 'myapp.desktop') if available.
 // Unlike libgtkui, this does *not* use "chromium-browser.desktop" as a
 // fallback.
