--- src/loadpng.c.orig	2003-09-30 14:55:20.000000000 +0200
+++ src/loadpng.c	2010-03-30 12:09:13.000000000 +0200
@@ -55,7 +55,7 @@
   }
   /* ensure that we opened a PNG file */
   fread( header, 1, 8, fd );
-  if ( ! png_check_sig( header, 8 ) ) {
+  if ( png_sig_cmp( header, 0, 8 ) ) {
     fclose(fd);
     fprintf(stderr,_("File %s does not have a valid PNG signature.\n"), file);
     return NULL;
