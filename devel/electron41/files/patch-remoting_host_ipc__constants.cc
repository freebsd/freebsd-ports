--- remoting/host/ipc_constants.cc.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/ipc_constants.cc
@@ -17,7 +17,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 // Use a different IPC name for debug builds so that we can run the host
@@ -48,7 +48,7 @@ constexpr char kAgentProcessBrokerIpcName[] =
 
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 constexpr char kLoginSessionReporterIpcName[] =
@@ -93,7 +93,7 @@ GetChromotingHostServicesServerName() {
   static const base::NoDestructor<mojo::NamedPlatformChannel::ServerName>
       server_name(
           named_mojo_ipc_server::WorkingDirectoryIndependentServerNameFromUTF8(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
               // Linux host creates the socket file in /tmp, and it won't be
               // deleted until reboot, so we put username in the path in case
               // the user switches the host owner.
@@ -126,7 +126,7 @@ GetAgentProcessBrokerServerName() {
 
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 const char kLoginSessionReporterMessagePipeId[] = "login-session-reporter";
 
