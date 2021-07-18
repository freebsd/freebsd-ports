--- content/shell/browser/shell_browser_main_parts.cc.orig	2021-04-14 01:08:48 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -55,7 +55,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -137,7 +137,7 @@ void ShellBrowserMainParts::PostMainMessageLoopStart()
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
