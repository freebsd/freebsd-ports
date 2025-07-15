--- chrome/browser/background/extensions/background_mode_manager.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/background/extensions/background_mode_manager.cc
@@ -893,7 +893,7 @@ gfx::ImageSkia GetStatusTrayIcon() {
   }
 
   return family->CreateExact(size).AsImageSkia();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return *ui::ResourceBundle::GetSharedInstance().GetImageSkiaNamed(
       IDR_PRODUCT_LOGO_128);
 #elif BUILDFLAG(IS_MAC)
