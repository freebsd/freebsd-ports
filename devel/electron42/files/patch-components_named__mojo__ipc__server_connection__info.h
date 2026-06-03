--- components/named_mojo_ipc_server/connection_info.h.orig	2026-04-28 21:06:17 UTC
+++ components/named_mojo_ipc_server/connection_info.h
@@ -13,7 +13,8 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+#include <sys/ucred.h>
 #include <sys/socket.h>
 #endif
 
@@ -30,8 +31,10 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
   ucred credentials{};
+#elif BUILDFLAG(IS_FREEBSD)
+  xucred credentials{};
 #elif BUILDFLAG(IS_WIN)
   // The process of the peer. Only valid if `include_peer_process_info` is true
   // in EndpointOptions.
