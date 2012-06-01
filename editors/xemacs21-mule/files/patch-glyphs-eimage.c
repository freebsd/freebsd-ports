--- src/glyphs-eimage.c.orig	2007-08-20 21:52:28.000000000 +0200
+++ src/glyphs-eimage.c	2012-05-02 20:31:49.000000000 +0200
@@ -65,6 +65,7 @@
 extern "C" {
 #endif
 #include <png.h>
+#include <pngpriv.h>
 #ifdef __cplusplus
 }
 #endif
