--- src/swft/swft_import_ttf.cpp.orig	2013-12-16 08:12:12.000000000 +0100
+++ src/swft/swft_import_ttf.cpp	2013-12-16 08:11:52.000000000 +0100
@@ -14,7 +14,7 @@
 #include FT_OUTLINE_H
 #include "SWFShapeMaker.h"
 
-#include <freetype/tttables.h>
+#include FT_TRUETYPE_TABLES_H
 
 using namespace SWF;
 
