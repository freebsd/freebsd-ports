--- electron/shell/app/electron_crash_reporter_client.cc.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/app/electron_crash_reporter_client.cc
@@ -196,7 +196,7 @@ void ElectronCrashReporterClient::GetProcessSimpleAnno
   (*annotations)["ver"] = ELECTRON_VERSION_STRING;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 bool ElectronCrashReporterClient::ShouldMonitorCrashHandlerExpensively() {
   return false;
 }
