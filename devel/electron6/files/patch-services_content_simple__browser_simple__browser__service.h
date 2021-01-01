--- services/content/simple_browser/simple_browser_service.h.orig	2019-09-10 11:14:11 UTC
+++ services/content/simple_browser/simple_browser_service.h
@@ -15,7 +15,7 @@
 #include "services/service_manager/public/cpp/service_binding.h"
 #include "services/service_manager/public/mojom/service.mojom.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #endif
 
@@ -45,7 +45,7 @@ class COMPONENT_EXPORT(SIMPLE_BROWSER) SimpleBrowserSe
   // service_manager::Service:
   void OnStart() override;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
