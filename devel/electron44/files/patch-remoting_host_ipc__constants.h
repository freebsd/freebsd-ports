--- remoting/host/ipc_constants.h.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/ipc_constants.h
@@ -31,7 +31,7 @@ GetChromotingHostServicesServerName();
 const mojo::NamedPlatformChannel::ServerName&
 GetChromotingHostServicesServerName();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the server name for the legacy single-process Linux host.
 const mojo::NamedPlatformChannel::ServerName&
 GetLegacyChromotingHostServicesServerName();
@@ -45,7 +45,7 @@ const mojo::NamedPlatformChannel::ServerName& GetAgent
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
