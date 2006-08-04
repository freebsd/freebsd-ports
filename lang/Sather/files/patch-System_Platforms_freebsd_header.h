--- System/Platforms/freebsd/header.h.orig	Thu Aug  3 00:32:26 2006
+++ System/Platforms/freebsd/header.h	Thu Aug  3 00:32:32 2006
@@ -16,7 +16,7 @@
 
 #define GC_DEBUG
-#  include <gc/gc.h>
+#  include <gc.h>
 #endif
 
 #include "../../Common/c_header.h"
