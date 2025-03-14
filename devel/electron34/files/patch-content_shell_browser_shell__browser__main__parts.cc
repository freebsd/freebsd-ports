--- content/shell/browser/shell_browser_main_parts.cc.orig	2023-10-19 19:58:22 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -51,7 +51,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -68,7 +68,7 @@
 #include "chromeos/lacros/dbus/lacros_dbus_thread_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"          // nogncheck
 #include "ui/linux/linux_ui_factory.h"  // nogncheck
 #endif
@@ -139,7 +139,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -168,7 +168,7 @@ void ShellBrowserMainParts::ToolkitInitialized() {
   if (switches::IsRunWebTestsSwitchPresent())
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(ui::GetDefaultLinuxUi());
 #endif
 }
@@ -215,7 +215,7 @@ void ShellBrowserMainParts::PostMainMessageLoopRun() {
   ShellDevToolsManagerDelegate::StopHttpHandler();
   browser_context_.reset();
   off_the_record_browser_context_.reset();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(nullptr);
 #endif
   performance_manager_lifetime_.reset();
