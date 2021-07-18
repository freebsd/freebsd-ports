--- chrome/test/base/interactive_ui_tests_main.cc.orig	2021-04-14 01:08:42 UTC
+++ chrome/test/base/interactive_ui_tests_main.cc
@@ -17,7 +17,7 @@
 #if defined(USE_AURA)
 #include "ui/aura/test/ui_controls_factory_aura.h"
 #include "ui/base/test/ui_controls_aura.h"
-#if defined(USE_OZONE) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_OZONE) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "ui/base/ui_base_features.h"
 #include "ui/ozone/public/ozone_platform.h"
 #include "ui/views/test/ui_controls_factory_desktop_aura_ozone.h"
@@ -55,7 +55,7 @@ class InteractiveUITestSuite : public ChromeTestSuite 
     com_initializer_.reset(new base::win::ScopedCOMInitializer());
     ui_controls::InstallUIControlsAura(
         aura::test::CreateUIControlsAura(nullptr));
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #if defined(USE_OZONE)
     if (features::IsUsingOzonePlatform()) {
       ui::OzonePlatform::InitParams params;
