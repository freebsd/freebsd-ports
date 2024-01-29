--- remoting/host/ipc_constants.cc.orig	2023-02-01 18:43:24 UTC
+++ remoting/host/ipc_constants.cc
@@ -17,7 +17,7 @@ namespace remoting {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 // Use a different IPC name for debug builds so that we can run the host
@@ -68,7 +68,7 @@ GetChromotingHostServicesServerName() {
   static const base::NoDestructor<mojo::NamedPlatformChannel::ServerName>
       server_name(
           named_mojo_ipc_server::WorkingDirectoryIndependentServerNameFromUTF8(
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
               // Linux host creates the socket file in /tmp, and it won't be
               // deleted until reboot, so we put username in the path in case
               // the user switches the host owner.
