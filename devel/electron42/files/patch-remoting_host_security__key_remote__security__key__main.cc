--- remoting/host/security_key/remote_security_key_main.cc.orig	2025-06-30 07:04:30 UTC
+++ remoting/host/security_key/remote_security_key_main.cc
@@ -24,7 +24,7 @@
 #include "remoting/host/security_key/security_key_message_handler.h"
 #include "remoting/host/usage_stats_consent.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -96,7 +96,7 @@ int RemoteSecurityKeyMain(int argc, char** argv) {
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
