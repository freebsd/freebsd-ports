--- electron/shell/app/electron_crash_reporter_client.h.orig	2023-04-03 22:25:21 UTC
+++ electron/shell/app/electron_crash_reporter_client.h
@@ -70,7 +70,7 @@ class ElectronCrashReporterClient : public crash_repor
   bool ReportingIsEnforcedByPolicy(bool* breakpad_enabled) override;
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool ShouldMonitorCrashHandlerExpensively() override;
 #endif
 
