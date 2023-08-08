--- services/plugins/dndcp/dndcp.cpp.orig	2023-03-07 22:57:07 UTC
+++ services/plugins/dndcp/dndcp.cpp
@@ -36,11 +36,9 @@
  */
 #include <glib.h>
 
-extern "C" {
 #include "vmware/guestrpc/tclodefs.h"
 #include "vmware/tools/plugin.h"
 #include "vmware/tools/utils.h"
-}
 
 #include <string.h>
 #include "copyPasteDnDWrapper.h"
