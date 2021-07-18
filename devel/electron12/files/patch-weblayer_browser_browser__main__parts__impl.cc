--- weblayer/browser/browser_main_parts_impl.cc.orig	2021-04-14 01:09:40 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -69,7 +69,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if defined(USE_AURA) && defined(OS_LINUX)
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -184,7 +184,7 @@ void BrowserMainPartsImpl::PreMainMessageLoopStart() {
 int BrowserMainPartsImpl::PreEarlyInitialization() {
   browser_process_ = std::make_unique<BrowserProcess>(std::move(local_state_));
 
-#if defined(USE_AURA) && defined(OS_LINUX)
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
