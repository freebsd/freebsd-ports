--- components/named_mojo_ipc_server/connection_info.h.orig	2023-02-01 18:43:16 UTC
+++ components/named_mojo_ipc_server/connection_info.h
@@ -13,7 +13,7 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/socket.h>
 #endif
 
@@ -32,7 +32,7 @@ struct ConnectionInfo {
   absl::optional<base::win::ScopedHandle> impersonation_token{};
 #elif BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ucred credentials{};
 #endif
 };
