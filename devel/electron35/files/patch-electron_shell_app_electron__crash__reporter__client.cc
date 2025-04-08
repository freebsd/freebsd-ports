--- electron/shell/app/electron_crash_reporter_client.cc.orig	2025-04-04 05:26:44 UTC
+++ electron/shell/app/electron_crash_reporter_client.cc
@@ -91,7 +91,7 @@ ElectronCrashReporterClient::~ElectronCrashReporterCli
 
 ElectronCrashReporterClient::~ElectronCrashReporterClient() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ElectronCrashReporterClient::SetCrashReporterClientIdFromGUID(
     const std::string& client_guid) {
   crash_keys::SetMetricsClientIdFromGUID(client_guid);
@@ -172,7 +172,7 @@ void ElectronCrashReporterClient::GetProcessSimpleAnno
   (*annotations)["ver"] = ELECTRON_VERSION_STRING;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 bool ElectronCrashReporterClient::ShouldMonitorCrashHandlerExpensively() {
   return false;
 }
