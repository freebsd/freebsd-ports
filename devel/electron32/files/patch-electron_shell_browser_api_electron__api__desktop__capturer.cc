--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2024-09-04 18:50:02 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -46,7 +46,7 @@ namespace {
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
