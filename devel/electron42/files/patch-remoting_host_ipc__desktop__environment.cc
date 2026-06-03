--- remoting/host/ipc_desktop_environment.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/ipc_desktop_environment.cc
@@ -341,7 +341,7 @@ void IpcDesktopEnvironmentFactory::OnTerminalDisconnec
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void IpcDesktopEnvironmentFactory::OnSessionServicesClientConnected(
     int terminal_id,
     mojo::PendingReceiver<mojom::ChromotingSessionServices> receiver) {
