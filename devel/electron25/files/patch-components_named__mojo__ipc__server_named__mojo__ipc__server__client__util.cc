--- components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc.orig	2023-02-01 18:43:16 UTC
+++ components/named_mojo_ipc_server/named_mojo_ipc_server_client_util.cc
@@ -22,7 +22,7 @@ namespace named_mojo_ipc_server {
 // static
 mojo::PlatformChannelEndpoint ConnectToServer(
     const mojo::NamedPlatformChannel::ServerName& server_name) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return mojo::NamedPlatformChannel::ConnectToServer(server_name);
 #elif BUILDFLAG(IS_MAC)
   mojo::PlatformChannelEndpoint endpoint =
