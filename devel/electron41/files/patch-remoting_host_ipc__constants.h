--- remoting/host/ipc_constants.h.orig	2026-03-13 16:54:03 UTC
+++ remoting/host/ipc_constants.h
@@ -38,7 +38,7 @@ const mojo::NamedPlatformChannel::ServerName& GetAgent
 const mojo::NamedPlatformChannel::ServerName& GetAgentProcessBrokerServerName();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Message pipe ID used for LoginSessionReporter.
 extern const char kLoginSessionReporterMessagePipeId[];
 
