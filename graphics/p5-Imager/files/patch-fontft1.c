--- fontft1.c.orig	2014-01-10 09:46:40 UTC
+++ fontft1.c
@@ -46,6 +46,9 @@ Some of these functions are internal.
 
    We need a compilation probe in Makefile.PL
 */
+#include <ft2build.h>
+#include FT_FREETYPE_H
+
 #define FTXPOST 1
 #define FTXERR18 1
 
