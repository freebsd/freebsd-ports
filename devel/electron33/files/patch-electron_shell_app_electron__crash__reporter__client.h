--- electron/shell/app/electron_crash_reporter_client.h.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/app/electron_crash_reporter_client.h
@@ -30,7 +30,7 @@ class ElectronCrashReporterClient : public crash_repor
       const std::map<std::string, std::string>& annotations);
 
   // crash_reporter::CrashReporterClient implementation.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetCrashReporterClientIdFromGUID(
       const std::string& client_guid) override;
   void GetProductNameAndVersion(const char** product_name,
@@ -69,7 +69,7 @@ class ElectronCrashReporterClient : public crash_repor
   bool ReportingIsEnforcedByPolicy(bool* breakpad_enabled) override;
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ShouldMonitorCrashHandlerExpensively() override;
 #endif
 
