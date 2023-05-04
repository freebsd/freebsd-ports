--- electron/shell/app/electron_crash_reporter_client.cc.orig	2023-04-03 22:25:21 UTC
+++ electron/shell/app/electron_crash_reporter_client.cc
@@ -197,7 +197,7 @@ void ElectronCrashReporterClient::GetProcessSimpleAnno
   (*annotations)["ver"] = ELECTRON_VERSION_STRING;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 bool ElectronCrashReporterClient::ShouldMonitorCrashHandlerExpensively() {
   return false;
 }
