--- fontft1.c-orig	2014-07-30 12:45:44.000000000 +0200
+++ fontft1.c	2014-07-30 12:46:05.000000000 +0200
@@ -46,6 +46,9 @@
 
    We need a compilation probe in Makefile.PL
 */
+#include <ft2build.h>
+#include FT_FREETYPE_H
+
 #define FTXPOST 1
 #define FTXERR18 1
 
