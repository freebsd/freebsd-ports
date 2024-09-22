--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -58,7 +58,7 @@ void ChromeBrowserMainExtraPartsLinux::InitOzonePlatfo
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* const command_line = base::CommandLine::ForCurrentProcess();
   auto env = base::Environment::Create();
   std::string desktop_startup_id;
