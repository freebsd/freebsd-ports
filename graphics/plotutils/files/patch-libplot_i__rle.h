
$FreeBSD$

--- libplot/i_rle.h.orig	Wed Mar  3 20:05:38 1999
+++ libplot/i_rle.h	Thu Aug  7 11:48:12 2003
@@ -35,7 +35,7 @@
   int obits;
   FILE *ofile;
 #ifdef LIBPLOTTER
-  ostream *outstream;
+  std::ostream *outstream;
 #endif
   unsigned char oblock[256];
   int oblen;
@@ -43,7 +43,7 @@
 
 /* create, initialize, and return a new RLE output structure */
 #ifdef LIBPLOTTER
-extern rle_out *_rle_init ____P((FILE *fp, ostream *out, int bit_depth));
+extern rle_out *_rle_init ____P((FILE *fp, std::ostream *out, int bit_depth));
 #else
 extern rle_out *_rle_init ____P((FILE *fp, int bit_depth));
 #endif
