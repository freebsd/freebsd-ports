--- services/plugins/dndcp/dndGuest/dndCPTransportGuestRpc.hpp.orig	2021-08-03 01:43:48 UTC
+++ services/plugins/dndcp/dndGuest/dndCPTransportGuestRpc.hpp
@@ -31,13 +31,11 @@
 
 #include "dnd.h"
 
-extern "C" {
 #ifdef VMX86_TOOLS
    #include "vmware/tools/guestrpc.h"
 #else
    #include "guest_rpc.h"
 #endif
-}
 
 #define GUEST_RPC_CMD_STR_DND "dnd.transport"
 #define GUEST_RPC_CMD_STR_CP  "copypaste.transport"
