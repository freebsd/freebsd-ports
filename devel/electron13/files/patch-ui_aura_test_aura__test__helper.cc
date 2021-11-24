--- ui/aura/test/aura_test_helper.cc.orig	2021-07-15 19:14:08 UTC
+++ ui/aura/test/aura_test_helper.cc
@@ -30,7 +30,7 @@
 #include "ui/wm/core/default_activation_client.h"
 #include "ui/wm/core/default_screen_position_client.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/platform_window/common/platform_window_defaults.h"  // nogncheck
 #endif
 
@@ -63,7 +63,7 @@ AuraTestHelper::AuraTestHelper(ui::ContextFactory* con
   DCHECK(!g_instance);
   g_instance = this;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ui::test::EnableTestConfigForPlatformWindows();
 #endif
 
