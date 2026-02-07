--- components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc.orig	2025-04-22 20:15:27 UTC
+++ components/named_mojo_ipc_server/named_mojo_server_endpoint_connector_linux.cc
@@ -89,7 +89,9 @@ void NamedMojoServerEndpointConnectorLinux::OnSocketRe
     PLOG(ERROR) << "getsockopt failed.";
     return;
   }
+#if !BUILDFLAG(IS_OPENBSD)
   info->pid = info->credentials.pid;
+#endif
 
   mojo::PlatformChannelEndpoint endpoint(
       mojo::PlatformHandle(std::move(connection_fd)));
