--- remoting/host/remoting_me2me_host.cc.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/remoting_me2me_host.cc
@@ -146,7 +146,7 @@
 #include "remoting/host/mac/permission_utils.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
 #include <gtk/gtk.h>
 
@@ -158,7 +158,7 @@
 #endif  // defined(REMOTING_USE_X11)
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #include "remoting/host/linux/audio_capturer_linux.h"
 #include "remoting/host/linux/certificate_watcher.h"
@@ -173,7 +173,7 @@
 #include "remoting/host/pairing_registry_delegate_win.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/host/host_wtmpdb_logger.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -199,7 +199,7 @@ constexpr base::FilePath::CharType kStdinConfigPath[] 
 // from stdin.
 constexpr base::FilePath::CharType kStdinConfigPath[] = FILE_PATH_LITERAL("-");
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // The command line switch used to pass name of the pipe to capture audio on
 // linux.
 const char kAudioPipeSwitchName[] = "audio-pipe-name";
@@ -423,7 +423,7 @@ class HostProcess : public ConfigWatcher::Delegate,
                     int line_number) override;
 
   // mojom::RemotingHostControl implementation.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ApplyHostConfig(base::DictValue serialized_config) override;
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -448,7 +448,7 @@ class HostProcess : public ConfigWatcher::Delegate,
   std::unique_ptr<AgentProcessBrokerClient> agent_process_broker_client_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Watch for certificate changes and kill the host when changes occur
   std::unique_ptr<CertificateWatcher> cert_watcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -514,7 +514,7 @@ class HostProcess : public ConfigWatcher::Delegate,
   std::unique_ptr<FtlEchoMessageListener> ftl_echo_message_listener_;
 
   std::unique_ptr<HostEventLogger> host_event_logger_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<HostWtmpdbLogger> host_wtmpdb_logger_;
 #endif
   std::unique_ptr<HostPowerSaveBlocker> power_save_blocker_;
@@ -843,7 +843,7 @@ void HostProcess::ShutdownOnNetworkThread() {
 void HostProcess::ShutdownOnNetworkThread() {
   DCHECK(context_->network_task_runner()->BelongsToCurrentThread());
   config_watcher_.reset();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   cert_watcher_.reset();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -927,7 +927,7 @@ void HostProcess::CreateAuthenticatorFactory() {
             context_->create_client_cert_store_callback(),
             service_account_email_, oauth_refresh_token_));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!cert_watcher_) {
       cert_watcher_ = std::make_unique<CertificateWatcher>(
           base::BindRepeating(&HostProcess::ShutdownHost,
@@ -1072,7 +1072,7 @@ void HostProcess::StartOnUiThread() {
       base::BindRepeating(&HostProcess::OnPolicyUpdate, base::Unretained(this)),
       base::BindRepeating(&HostProcess::OnPolicyError, base::Unretained(this)));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // If an audio pipe is specific on the command-line then initialize
   // AudioCapturerLinux to capture from it.
   base::FilePath audio_pipe_name =
@@ -1147,7 +1147,7 @@ void HostProcess::ShutdownOnUiThread() {
   // It is now safe for the HostProcess to be deleted.
   self_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Cause the global AudioPipeReader to be freed, otherwise the audio
   // thread will remain in-use and prevent the process from exiting.
   // TODO(wez): DesktopEnvironmentFactory should own the pipe reader.
@@ -1155,7 +1155,7 @@ void HostProcess::ShutdownOnUiThread() {
   AudioCapturerLinux::InitializePipeReader(nullptr, base::FilePath());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   context_->input_task_runner()->PostTask(
       FROM_HERE,
       base::BindOnce([]() { delete ui::X11EventSource::GetInstance(); }));
@@ -1248,7 +1248,7 @@ void HostProcess::BindRemotingHostControl(
 
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void HostProcess::ApplyHostConfig(base::DictValue config) {
   DCHECK(context_->ui_task_runner()->BelongsToCurrentThread());
   OnConfigParsed(std::move(config));
@@ -1778,7 +1778,7 @@ void HostProcess::InitializeSignaling() {
   zombie_host_detector_ = std::make_unique<ZombieHostDetector>(base::BindOnce(
       &HostProcess::OnZombieStateDetected, base::Unretained(this)));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO: joedow - Remove Linux scope after this codepath has been stabilized.
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->HasSwitch(kEnableCorpMessaging)) {
@@ -1874,7 +1874,7 @@ void HostProcess::StartHost() {
 
   SetState(HOST_STARTED);
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   if (webrtc::DesktopCapturer::IsRunningUnderWayland()) {
     if (GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
       GnomeRemoteDesktopSession::GetInstance()->Init(
@@ -1988,7 +1988,7 @@ void HostProcess::StartHost() {
 
   host_->AddExtension(std::make_unique<TestEchoExtension>());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   if (cmd_line->HasSwitch(kEnableWtmpdb)) {
     host_wtmpdb_logger_ =
@@ -2023,7 +2023,7 @@ void HostProcess::StartHost() {
   // addresses.
   host_->Start(*host_owner_emails_.begin());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For Windows and Mac, ChromotingHostServices connections are handled by
   // another process, then the message pipe is forwarded to the network process.
   host_->StartChromotingHostServices();
@@ -2172,7 +2172,7 @@ int HostProcessMain(bool multi_process) {
                                                    : " (single-process)");
   const base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if defined(REMOTING_USE_X11)
   // Initialize Xlib for multi-threaded use, allowing non-Chromium code to
   // use X11 safely (such as the WebRTC capturer, GTK ...)
@@ -2217,7 +2217,7 @@ int HostProcessMain(bool multi_process) {
     return kInitializationFailed;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Log and cleanup the crash database. We do this after a short delay so that
   // the crash database has a chance to be updated properly if we just got
   // relaunched after a crash.
@@ -2237,7 +2237,7 @@ int HostProcessMain(bool multi_process) {
   std::unique_ptr<net::NetworkChangeNotifier> network_change_notifier(
       net::NetworkChangeNotifier::CreateIfNeeded());
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   // Create an X11EventSource on all UI threads, so the global X11 connection
   // (x11::Connection::Get()) can dispatch X events.
   auto event_source =
