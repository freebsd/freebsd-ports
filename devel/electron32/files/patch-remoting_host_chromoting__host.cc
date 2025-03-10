--- remoting/host/chromoting_host.cc.orig	2024-02-21 00:20:51 UTC
+++ remoting/host/chromoting_host.cc
@@ -129,7 +129,7 @@ void ChromotingHost::Start(const std::string& host_own
       &ChromotingHost::OnIncomingSession, base::Unretained(this)));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
