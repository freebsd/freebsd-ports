--- src/store.h.orig	Sat May 17 15:34:24 2003
+++ src/store.h	Mon May 24 22:08:54 2004
@@ -32,8 +32,8 @@
 
 #include <string>
 #include <map>
-#include <freetype/freetype.h>
-
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 
 class Store
