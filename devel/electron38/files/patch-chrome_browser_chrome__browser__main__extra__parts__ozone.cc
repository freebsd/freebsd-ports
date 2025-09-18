--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -28,7 +28,7 @@ void ChromeBrowserMainExtraPartsOzone::PostMainMessage
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
