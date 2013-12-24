--- appFrame/appFontConfig.c.orig	2013-12-13 10:45:38.000000000 +0100
+++ appFrame/appFontConfig.c	2013-12-13 10:46:24.000000000 +0100
@@ -889,7 +889,7 @@
 
     static const n2s xftn2s[]=
     {
-#   include <freetype/fterrdef.h>
+#   include FT_ERROR_DEFINITIONS_H
     };
 
     for ( i= 0; i < sizeof(xftn2s)/sizeof(n2s); i++ )
