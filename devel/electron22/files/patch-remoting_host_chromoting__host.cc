--- remoting/host/chromoting_host.cc.orig	2022-02-28 16:54:41 UTC
+++ remoting/host/chromoting_host.cc
@@ -124,7 +124,7 @@ void ChromotingHost::StartChromotingHostServices() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!ipc_server_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   ipc_server_ = std::make_unique<MojoIpcServer<mojom::ChromotingHostServices>>(
       GetChromotingHostServicesServerName(), this);
   ipc_server_->StartServer();
