--- electron/shell/browser/electron_browser_main_parts.cc.orig	2026-09-04 00:15:46 UTC
+++ electron/shell/browser/electron_browser_main_parts.cc
@@ -81,7 +81,7 @@
 #include "ui/wm/core/wm_state.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 
 #include "base/environment.h"
@@ -141,7 +141,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The display server connection or the session bus is gone: exit like
 // Chrome's SessionEnding(), with an off-thread watchdog that crashes us if
 // exiting hangs on the dead connection.
@@ -213,13 +213,17 @@ ElectronBrowserMainParts::ElectronBrowserMainParts()
   self_ = this;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace {
 
 // Resolved via dlsym: a direct reference would bind to Chromium's bundled
 // FontConfig rather than the system copy GTK and Pango use.
 void* SystemFontConfigSymbol(const char* name) {
+#if BUILDFLAG(IS_BSD)
+  void* lib = dlopen("libfontconfig.so", RTLD_NOW);
+#else
   void* lib = dlopen("libfontconfig.so.1", RTLD_NOW);
+#endif
   return lib ? dlsym(lib, name) : nullptr;
 }
 
@@ -250,10 +254,10 @@ std::vector<std::optional<std::string>> SnapshotFontCo
 }
 
 }  // namespace
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 ElectronBrowserMainParts::~ElectronBrowserMainParts() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   JoinSystemFontConfigInit();
 #endif
 }
@@ -320,7 +324,7 @@ void ElectronBrowserMainParts::PostEarlyInitialization
 
   node_bindings_->Initialize(isolate, context);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Runs during Node.js environment creation and is joined before any app
   // code can run, so nothing else touches FontConfig or the environment.
   const auto fontconfig_env = SnapshotFontConfigEnv();
@@ -356,7 +360,7 @@ void ElectronBrowserMainParts::PostEarlyInitialization
   // Wrap the uv loop with global env.
   node_bindings_->set_uv_env(node_env_.get());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   JoinSystemFontConfigInit();
 #endif
 
@@ -366,7 +370,7 @@ void ElectronBrowserMainParts::PostEarlyInitialization
   // Wait for app
   node_bindings_->JoinAppCode();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reload if the app's main script changed the FontConfig environment.
   if (fontconfig_env != SnapshotFontConfigEnv()) {
     if (auto fc_reinit = reinterpret_cast<int (*)()>(
@@ -426,7 +430,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   // happen before the ResourceBundle is loaded
   if (locale.empty())
     l10n_util::OverrideLocaleWithCocoaLocale();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // l10n_util::GetApplicationLocaleInternal uses g_get_language_names(),
   // which keys off of getenv("LC_ALL").
   // We must set this env first to make ui::ResourceBundle accept the custom
@@ -455,7 +459,7 @@ int ElectronBrowserMainParts::PreCreateThreads() {
   ElectronBrowserClient::SetApplicationLocale(app_locale);
   fake_browser_process_->SetApplicationLocale(app_locale);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Reset to the original LC_ALL since we should not be changing it.
   if (!locale.empty()) {
     if (lc_all)
@@ -511,7 +515,7 @@ void ElectronBrowserMainParts::ToolkitInitialized() {
 }
 
 void ElectronBrowserMainParts::ToolkitInitialized() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // GTK3's gtk_init() probes the display for OpenGL and loads the GL driver
   // into this process; nothing here uses GdkGLContext. GDK_GL is read once at
   // init and only by GTK3 (GTK4 renders with GL itself and ignores it).
@@ -561,14 +565,14 @@ void ElectronBrowserMainParts::ToolkitInitialized() {
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ElectronBrowserMainParts::JoinSystemFontConfigInit() {
   if (system_fontconfig_thread_.is_null())
     return;
   base::PlatformThread::Join(system_fontconfig_thread_);
   system_fontconfig_thread_ = base::PlatformThreadHandle();
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 int ElectronBrowserMainParts::PreMainMessageLoopRun() {
   // Run user's main script before most things get initialized, so we can have
@@ -641,19 +645,23 @@ void ElectronBrowserMainParts::PostCreateMainMessageLo
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
@@ -750,7 +758,7 @@ void ElectronBrowserMainParts::PostMainMessageLoopRun(
   fake_browser_process_->PostMainMessageLoopRun();
   content::DevToolsAgentHost::StopRemoteDebuggingPipeHandler();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
