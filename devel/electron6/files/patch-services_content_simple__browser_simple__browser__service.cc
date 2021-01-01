--- services/content/simple_browser/simple_browser_service.cc.orig	2019-09-10 11:14:11 UTC
+++ services/content/simple_browser/simple_browser_service.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "services/content/simple_browser/window.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"  // nogncheck
 #endif
 
@@ -23,7 +23,7 @@ SimpleBrowserService::~SimpleBrowserService() = defaul
 
 void SimpleBrowserService::OnStart() {
   if (ui_initialization_mode_ == UIInitializationMode::kInitializeUI) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     font_loader_ =
         sk_make_sp<font_service::FontLoader>(service_binding_.GetConnector());
     SkFontConfigInterface::SetGlobal(font_loader_);
