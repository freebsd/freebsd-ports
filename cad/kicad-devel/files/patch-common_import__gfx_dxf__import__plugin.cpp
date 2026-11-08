--- common/import_gfx/dxf_import_plugin.cpp.orig	2026-10-01 19:47:08 UTC
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -38,6 +38,9 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
 
 /*
  * Important notes
