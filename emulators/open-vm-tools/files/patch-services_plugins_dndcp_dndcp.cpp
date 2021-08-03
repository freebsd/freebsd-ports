--- services/plugins/dndcp/dndcp.cpp.orig	2021-08-03 01:47:47 UTC
+++ services/plugins/dndcp/dndcp.cpp
@@ -31,11 +31,9 @@
 
 #define G_LOG_DOMAIN "dndcp"
 
-extern "C" {
 #include "vmware/guestrpc/tclodefs.h"
 #include "vmware/tools/plugin.h"
 #include "vmware/tools/utils.h"
-}
 
 #include <string.h>
 #include "copyPasteDnDWrapper.h"
