--- components/named_mojo_ipc_server/connection_info.h.orig	2025-04-22 20:15:27 UTC
+++ components/named_mojo_ipc_server/connection_info.h
@@ -12,7 +12,10 @@
 #include "base/win/scoped_handle.h"
 #elif BUILDFLAG(IS_MAC)
 #include <bsm/libbsm.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_OPENBSD)
+#include <sys/ucred.h>
+#endif
 #include <sys/socket.h>
 #endif
 
@@ -29,7 +32,7 @@ struct ConnectionInfo {
   base::ProcessId pid{};
 #if BUILDFLAG(IS_MAC)
   audit_token_t audit_token{};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
   ucred credentials{};
 #endif
 };
