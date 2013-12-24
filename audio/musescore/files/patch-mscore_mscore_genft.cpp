--- mscore/mscore/genft.cpp.orig	2013-12-13 09:46:58.000000000 +0100
+++ mscore/mscore/genft.cpp	2013-12-13 09:50:06.000000000 +0100
@@ -27,7 +27,7 @@
 
 #include <ft2build.h>
 #include FT_FREETYPE_H
-#include <freetype/tttables.h>
+#include FT_TRUETYPE_TABLES_H
 #include "al/xml.h"
 
 QMap<int, int> codemap;
