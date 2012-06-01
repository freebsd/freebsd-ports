--- src/glyphs-eimage.c.orig	2007-02-21 11:49:33.000000000 +0100
+++ src/glyphs-eimage.c	2012-05-02 20:02:02.000000000 +0200
@@ -61,6 +61,7 @@
 
 #define message message_ /* Yuck */
 #include <png.h>
+#include <pngpriv.h>
 #undef message
 
 END_C_DECLS
