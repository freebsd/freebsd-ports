--- src/loadpng.c.orig	2003-09-30 14:55:20.000000000 +0200
+++ src/loadpng.c	2012-04-29 13:39:04.000000000 +0200
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <png.h>
+#include <pngpriv.h>
 
 #include "gettext.h"
 
@@ -55,7 +56,7 @@
   }
   /* ensure that we opened a PNG file */
   fread( header, 1, 8, fd );
-  if ( ! png_check_sig( header, 8 ) ) {
+  if ( png_sig_cmp( header, 0, 8 ) ) {
     fclose(fd);
     fprintf(stderr,_("File %s does not have a valid PNG signature.\n"), file);
     return NULL;
@@ -73,7 +74,7 @@
     return NULL;
   }
   /* libpng does a longjmp here when it encounters an error */
-  if ( setjmp( png_ptr->jmpbuf ) ) {
+  if ( setjmp( png_jmpbuf(png_ptr) ) ) {
     png_destroy_read_struct( &png_ptr, &info_ptr, NULL);
     fclose(fd);
     return NULL;
