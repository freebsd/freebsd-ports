--- mod_map/file_png.c.orig	2009-07-22 04:02:45.000000000 +0200
+++ mod_map/file_png.c	2012-05-27 11:54:18.000000000 +0200
@@ -24,6 +24,7 @@
 /* --------------------------------------------------------------------------- */
 
 #include <png.h>
+#include <pngpriv.h>
 
 #include "mod_map.h"
 
@@ -89,7 +90,7 @@
 
     /* Rutina de error */
 
-    if ( setjmp( png_ptr->jmpbuf ) )
+    if ( setjmp( png_jmpbuf(png_ptr) ) )
     {
         png_destroy_read_struct( &png_ptr, &info_ptr, &end_info ) ;
         file_close( png ) ;
@@ -286,7 +287,7 @@
 
     /* Fin */
 
-    if ( !setjmp( png_ptr->jmpbuf ) ) png_read_end( png_ptr, 0 ) ;
+    if ( !setjmp( png_jmpbuf(png_ptr) ) ) png_read_end( png_ptr, 0 ) ;
 
     bitmap->modified = 1 ;
 
@@ -356,7 +357,7 @@
 
     /* Error handling... */
 
-    if ( setjmp( png_ptr->jmpbuf ) )
+    if ( setjmp( png_jmpbuf(png_ptr) ) )
     {
         png_destroy_write_struct( &png_ptr, NULL ) ;
         free( rowpointers ) ;
