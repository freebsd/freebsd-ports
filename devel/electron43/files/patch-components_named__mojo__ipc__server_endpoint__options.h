--- components/named_mojo_ipc_server/endpoint_options.h.orig	2026-10-14 12:14:13 UTC
+++ components/named_mojo_ipc_server/endpoint_options.h
@@ -77,7 +77,7 @@ struct EndpointOptions {
   std::wstring security_descriptor;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Iff this is true, connecting clients running as a different user from the
   // server (i.e. the calling process) will be rejected.
   bool require_same_peer_user = true;
