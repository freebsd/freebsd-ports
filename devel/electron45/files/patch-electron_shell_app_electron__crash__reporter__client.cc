--- electron/shell/app/electron_crash_reporter_client.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/app/electron_crash_reporter_client.cc
@@ -94,7 +94,7 @@ ElectronCrashReporterClient::~ElectronCrashReporterCli
 
 ElectronCrashReporterClient::~ElectronCrashReporterClient() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ElectronCrashReporterClient::SetCrashReporterClientIdFromGUID(
     const std::string& client_guid) {
   crash_keys::SetMetricsClientIdFromGUID(client_guid);
@@ -249,7 +249,7 @@ ElectronCrashReporterClient::GetExtraProcessAnnotation
   return annotations;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 bool ElectronCrashReporterClient::ShouldMonitorCrashHandlerExpensively() {
   return false;
 }
