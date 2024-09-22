--- electron/shell/app/electron_crash_reporter_client.h.orig	2024-06-24 09:53:23 UTC
+++ electron/shell/app/electron_crash_reporter_client.h
@@ -31,7 +31,7 @@ class ElectronCrashReporterClient : public crash_repor
       const std::map<std::string, std::string>& annotations);
 
   // crash_reporter::CrashReporterClient implementation.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetCrashReporterClientIdFromGUID(
       const std::string& client_guid) override;
   void GetProductNameAndVersion(const char** product_name,
@@ -70,7 +70,7 @@ class ElectronCrashReporterClient : public crash_repor
   bool ReportingIsEnforcedByPolicy(bool* breakpad_enabled) override;
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ShouldMonitorCrashHandlerExpensively() override;
 #endif
 
