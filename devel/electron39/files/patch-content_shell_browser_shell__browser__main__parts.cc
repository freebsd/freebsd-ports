--- content/shell/browser/shell_browser_main_parts.cc.orig	2025-04-22 20:15:27 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -50,7 +50,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(USE_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_AURA)
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -61,7 +61,7 @@
 #include "device/bluetooth/floss/floss_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "device/bluetooth/dbus/dbus_bluez_manager_wrapper_linux.h"
 #include "ui/linux/linux_ui.h"          // nogncheck
 #include "ui/linux/linux_ui_factory.h"  // nogncheck
@@ -128,7 +128,7 @@ int ShellBrowserMainParts::PreEarlyInitialization() {
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if BUILDFLAG(IS_LINUX) && defined(USE_AURA)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(USE_AURA)
   ui::InitializeInputMethodForTesting();
 #elif BUILDFLAG(IS_ANDROID)
   net::NetworkChangeNotifier::SetFactory(
@@ -156,7 +156,7 @@ void ShellBrowserMainParts::ToolkitInitialized() {
   if (switches::IsRunWebTestsSwitchPresent())
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(ui::GetDefaultLinuxUi());
 #endif
 }
@@ -203,7 +203,7 @@ void ShellBrowserMainParts::PostMainMessageLoopRun() {
   ShellDevToolsManagerDelegate::StopHttpHandler();
   browser_context_.reset();
   off_the_record_browser_context_.reset();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(nullptr);
 #endif
   performance_manager_lifetime_.reset();
