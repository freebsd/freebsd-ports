--- components/named_mojo_ipc_server/connection_info.h.orig	2024-04-15 20:33:54 UTC
+++ components/named_mojo_ipc_server/connection_info.h
@@ -14,7 +14,7 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/socket.h>
 #endif
 
@@ -33,7 +33,7 @@ struct ConnectionInfo {
   std::optional<base::win::ScopedHandle> impersonation_token{};
 #elif BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
