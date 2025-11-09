--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2025-04-04 05:26:44 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -48,7 +48,7 @@ namespace {
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
