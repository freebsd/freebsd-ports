--- headless/lib/browser/headless_browser_main_parts.h.orig	2021-07-15 19:13:40 UTC
+++ headless/lib/browser/headless_browser_main_parts.h
@@ -46,7 +46,7 @@ class HeadlessBrowserMainParts : public content::Brows
   void PreMainMessageLoopStart() override;
   device::GeolocationSystemPermissionManager* GetLocationPermissionManager();
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   void PostMainMessageLoopStart() override;
 #endif
   void QuitMainMessageLoop();
