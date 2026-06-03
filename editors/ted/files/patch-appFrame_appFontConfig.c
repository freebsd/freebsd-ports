--- appFrame/appFontConfig.c.orig	2013-02-01 12:11:08 UTC
+++ appFrame/appFontConfig.c
@@ -889,7 +889,7 @@ static const char * appFtErrorStr( int e )
 
     static const n2s xftn2s[]=
     {
-#   include <freetype/fterrdef.h>
+#   include FT_ERROR_DEFINITIONS_H
     };
 
     for ( i= 0; i < sizeof(xftn2s)/sizeof(n2s); i++ )
