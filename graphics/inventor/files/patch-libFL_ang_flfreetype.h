--- libFL/ang/flfreetype.h.orig	Sat Apr  3 02:18:41 2004
+++ libFL/ang/flfreetype.h	Sat Apr  3 02:19:07 2004
@@ -1,7 +1,8 @@
 #ifndef __flfreetype_h_
 #define __flfreetype_h_
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #ifndef __fl_h_
 #include "fl.h"
