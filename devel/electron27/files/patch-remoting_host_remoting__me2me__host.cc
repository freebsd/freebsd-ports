--- remoting/host/remoting_me2me_host.cc.orig	2023-10-19 19:58:29 UTC
+++ remoting/host/remoting_me2me_host.cc
@@ -126,7 +126,7 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 #endif  // defined(REMOTING_USE_X11)
@@ -137,13 +137,13 @@
 #endif  // defined(REMOTING_USE_X11)
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "remoting/host/audio_capturer_linux.h"
 #include "remoting/host/linux/certificate_watcher.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/host_utmp_logger.h"
 #endif
 
@@ -156,7 +156,7 @@
 #include "remoting/host/win/session_desktop_environment.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/wayland_manager.h"
 #include "remoting/host/linux/wayland_utils.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -186,7 +186,7 @@ const char kApplicationName[] = "chromoting";
 const char kStdinConfigPath[] = "-";
 #endif  // !defined(REMOTING_MULTI_PROCESS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The command line switch used to pass name of the pipe to capture audio on
 // linux.
 const char kAudioPipeSwitchName[] = "audio-pipe-name";
@@ -397,7 +397,7 @@ class HostProcess : public ConfigWatcher::Delegate,
 
   std::unique_ptr<ChromotingHostContext> context_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -466,7 +466,7 @@ class HostProcess : public ConfigWatcher::Delegate,
 
   std::unique_ptr<HostStatusLogger> host_status_logger_;
   std::unique_ptr<HostEventLogger> host_event_logger_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<HostUTMPLogger> host_utmp_logger_;
 #endif
   std::unique_ptr<HostPowerSaveBlocker> power_save_blocker_;
@@ -775,7 +775,7 @@ void HostProcess::StartOnNetworkThread() {
 void HostProcess::ShutdownOnNetworkThread() {
   DCHECK(context_->network_task_runner()->BelongsToCurrentThread());
   config_watcher_.reset();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   cert_watcher_.reset();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -836,7 +836,7 @@ void HostProcess::CreateAuthenticatorFactory() {
     DCHECK(third_party_auth_config_.token_url.is_valid());
     DCHECK(third_party_auth_config_.token_validation_url.is_valid());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!cert_watcher_) {
       cert_watcher_ = std::make_unique<CertificateWatcher>(
           base::BindRepeating(&HostProcess::ShutdownHost,
@@ -955,13 +955,13 @@ void HostProcess::StartOnUiThread() {
       base::BindRepeating(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::BindRepeating(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     WaylandManager::Get()->Init(context_->ui_task_runner());
   }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name =
@@ -1033,7 +1033,7 @@ void HostProcess::ShutdownOnUiThread() {
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1041,7 +1041,7 @@ void HostProcess::ShutdownOnUiThread() {
   AudioCapturerLinux::InitializePipeReader(nullptr, base::FilePath());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   context_->input_task_runner()->PostTask(
       FROM_HERE,
       base::BindOnce([]() { delete ui::X11EventSource::GetInstance(); }));
@@ -1392,7 +1392,7 @@ bool HostProcess::OnUsernamePolicyUpdate(const base::V
   // Returns false: never restart the host after this policy update.
   DCHECK(context_->network_task_runner()->BelongsToCurrentThread());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   absl::optional<bool> host_username_match_required =
       policies.FindBool(policy::key::kRemoteAccessHostMatchUsername);
   if (!host_username_match_required.has_value()) {
@@ -1801,7 +1801,7 @@ void HostProcess::StartHost() {
   // won't be advertised if it's missing a registry key or something.
   desktop_environment_options_.set_enable_remote_open_url(true);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   desktop_environment_options_.set_enable_remote_webauthn(is_googler_);
 #endif
 
@@ -1834,7 +1834,7 @@ void HostProcess::StartHost() {
   host_status_logger_ = std::make_unique<HostStatusLogger>(
       host_->status_monitor(), log_to_server_.get());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->HasSwitch(kEnableUtempter)) {
     host_utmp_logger_ =
@@ -1866,7 +1866,7 @@ void HostProcess::StartHost() {
 
   host_->Start(host_owner_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For Windows, ChromotingHostServices connections are handled by the daemon
   // process, then the message pipe is forwarded to the network process.
   host_->StartChromotingHostServices();
@@ -1999,7 +1999,7 @@ int HostProcessMain() {
   HOST_LOG << "Starting host process: version " << STRINGIZE(VERSION);
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
@@ -2048,7 +2048,7 @@ int HostProcessMain() {
   std::unique_ptr<net::NetworkChangeNotifier> network_change_notifier(
       net::NetworkChangeNotifier::CreateIfNeeded());
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
