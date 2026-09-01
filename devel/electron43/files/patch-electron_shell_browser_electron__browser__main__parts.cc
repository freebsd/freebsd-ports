--- electron/shell/browser/electron_browser_main_parts.cc.orig	2026-08-31 00:54:38 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -81,7 +81,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "chrome/browser/ui/views/dark_mode_manager_linux.h"
 #include "components/dbus/thread_linux/dbus_thread_linux.h"
@@ -139,7 +139,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The display server connection or the session bus is gone: exit like
 // Chrome's SessionEnding(), with an off-thread watchdog that crashes us if
 // exiting hangs on the dead connection.
@@ -356,7 +356,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -385,7 +385,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -441,7 +441,7 @@ void ElectronBrowserMainParts::ToolkitInitialized() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // GTK3's gtk_init() probes the display for OpenGL and loads the GL driver
   // into this process; nothing here uses GdkGLContext. GDK_GL is read once at
   // init and only by GTK3 (GTK4 renders with GL itself and ignores it).
@@ -562,19 +562,23 @@ void ElectronBrowserMainParts::PostCreateMainMessageLo
 }
 
 void ElectronBrowserMainParts::PostCreateMainMessageLoop() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::string app_name = electron::Browser::Get()->GetName();
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostCreateMainMessageLoop(
       base::BindOnce(&ExitOnSessionLoss),
       content::GetUIThreadTaskRunner({content::BrowserTaskType::kUserInput}));
   dbus_thread_linux::SetDisconnectedCallback(
       base::BindRepeating(&ExitOnSessionLoss));
 
+#if BUILDFLAG(IS_LINUX)
   if (!bluez::BluezDBusManager::IsInitialized())
     bluez::DBusBluezManagerWrapperLinux::Initialize();
+#endif
+#endif
 
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
   // network service for encrypted cookie storage.
@@ -671,7 +675,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
