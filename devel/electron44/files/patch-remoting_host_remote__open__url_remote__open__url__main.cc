--- remoting/host/remote_open_url/remote_open_url_main.cc.orig	2026-06-23 23:37:18 UTC
+++ remoting/host/remote_open_url/remote_open_url_main.cc
@@ -22,7 +22,7 @@
 #include "remoting/host/usage_stats_consent.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -46,7 +46,7 @@ int RemoteOpenUrlMain(int argc, char** argv) {
 
 #if defined(REMOTING_ENABLE_CRASH_REPORTING)
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
