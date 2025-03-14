--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -47,7 +47,7 @@ namespace {
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
