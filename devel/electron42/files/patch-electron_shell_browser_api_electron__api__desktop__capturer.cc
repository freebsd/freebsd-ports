--- electron/shell/browser/api/electron_api_desktop_capturer.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/api/electron_api_desktop_capturer.cc
@@ -51,7 +51,7 @@ namespace {
 #endif
 
 namespace {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Private function in ui/base/x/x11_display_util.cc
 base::flat_map<x11::RandR::Output, int> GetMonitors(
     std::pair<uint32_t, uint32_t> version,
