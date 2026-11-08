--- chrome/browser/background/extensions/background_mode_manager.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/background/extensions/background_mode_manager.cc
@@ -871,7 +871,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
   }
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
