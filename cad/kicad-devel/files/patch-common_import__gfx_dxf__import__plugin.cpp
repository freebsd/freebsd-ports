--- common/import_gfx/dxf_import_plugin.cpp.orig	2026-03-05 18:39:15 UTC
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -41,6 +41,9 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
 
 /*
  * Important notes
