--- services/content/simple_browser/simple_browser_service.h.orig	2019-03-15 06:37:32 UTC
+++ services/content/simple_browser/simple_browser_service.h
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "services/service_manager/public/cpp/service.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #endif
 
@@ -35,7 +35,7 @@ class COMPONENT_EXPORT(SIMPLE_BROWSER) SimpleBrowserSe
   // service_manager::Service:
   void OnStart() override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
