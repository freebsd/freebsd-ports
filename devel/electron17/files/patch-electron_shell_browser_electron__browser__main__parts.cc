--- electron/shell/browser/electron_browser_main_parts.cc.orig	2022-05-25 15:32:53 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -64,7 +64,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "device/bluetooth/bluetooth_adapter_factory.h"
@@ -143,7 +143,7 @@ std::u16string MediaStringProvider(media::MessageId id
   }
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // GTK does not provide a way to check if current theme is dark, so we compare
 // the text and background luminosity to get a result.
 // This trick comes from FireFox.
@@ -161,7 +161,7 @@ void UpdateDarkThemeSetting() {
 
 }  // namespace
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class DarkThemeObserver : public ui::NativeThemeObserver {
  public:
   DarkThemeObserver() = default;
@@ -214,7 +214,7 @@ int ElectronBrowserMainParts::PreEarlyInitialization()
 #if defined(OS_POSIX)
   HandleSIGCHLD();
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::OzonePlatform::PreEarlyInitialization();
 #endif
 
@@ -275,7 +275,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
 #if defined(USE_AURA)
   screen_ = views::CreateDesktopScreen();
   display::Screen::SetScreenInstance(screen_.get());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   views::LinuxUI::instance()->UpdateDeviceScaleFactor();
 #endif
 #endif
@@ -292,7 +292,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -315,7 +315,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -362,7 +362,7 @@ void ElectronBrowserMainParts::PostDestroyThreads() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   auto linux_ui = BuildGtkUi();
   linux_ui->Initialize();
   DCHECK(ui::LinuxInputMethodContextFactory::instance());
@@ -469,7 +469,9 @@ void ElectronBrowserMainParts::PostCreateMainMessageLo
   ui::OzonePlatform::GetInstance()->PostCreateMainMessageLoop(
       std::move(shutdown_cb));
   bluez::DBusBluezManagerWrapperLinux::Initialize();
+#endif
 
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
   // network service for encrypted cookie storage.
@@ -528,7 +530,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
