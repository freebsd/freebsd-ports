--- remoting/host/host_main.cc.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/host_main.cc
@@ -47,7 +47,7 @@ int NetworkProcessMain();
 // Known entry points.
 int SingleProcessHostProcessMain();
 int NetworkProcessMain();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int DaemonProcessMain();
 int DesktopProcessMain();
 #endif
@@ -56,7 +56,7 @@ int UrlForwarderConfiguratorMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -70,7 +70,7 @@ void Usage(const base::FilePath& program_name) {
       "\n"
       "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
       "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -150,7 +150,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
     main_routine = &SingleProcessHostProcessMain;
   } else if (process_type == kProcessTypeNetwork) {
     main_routine = &NetworkProcessMain;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeDaemon) {
     main_routine = &DaemonProcessMain;
   } else if (process_type == kProcessTypeDesktop) {
@@ -164,7 +164,7 @@ MainRoutineFn SelectMainRoutine(const std::string& pro
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -232,7 +232,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
@@ -276,7 +276,7 @@ int HostMain(int argc, char** argv) {
   // Mac, where the broker process is the agent process broker.
   is_broker_process |= main_routine == &SingleProcessHostProcessMain;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For multi-process hosts, the daemon process acts as the broker.
   is_broker_process |= main_routine == &DaemonProcessMain;
 #endif
