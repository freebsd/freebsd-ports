--- common/import_gfx/dxf_import_plugin.cpp.orig	2024-03-23 15:57:26 UTC
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -41,6 +41,10 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
+
 
 /*
  * Important notes
