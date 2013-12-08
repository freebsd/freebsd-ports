--- src/libnrtype/FontFactory.h.orig	2013-12-08 11:01:49.000000000 +0100
+++ src/libnrtype/FontFactory.h	2013-12-08 11:02:22.000000000 +0100
@@ -31,7 +31,8 @@
 #include <pango/pangowin32.h>
 #else
 #include <pango/pangoft2.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #endif
 
 namespace Glib
