--- remoting/host/chromoting_host.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/chromoting_host.cc
@@ -145,7 +145,7 @@ void ChromotingHost::Start(const std::string& host_own
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
