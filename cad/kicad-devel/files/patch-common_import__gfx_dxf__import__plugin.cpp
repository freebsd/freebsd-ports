--- common/import_gfx/dxf_import_plugin.cpp.orig	2026-06-23 12:40:47 UTC
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -37,6 +37,9 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
 
 /*
  * Important notes
