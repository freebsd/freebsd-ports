
$FreeBSD$

--- libplot/i_rle.c.orig	Sun Jun 27 11:58:10 1999
+++ libplot/i_rle.c	Thu Aug  7 11:48:12 2003
@@ -78,7 +78,7 @@
   else if (rle->outstream)
     {
       rle->outstream->put ((unsigned char)(rle->oblen));
-      rle->outstream->write (&(rle->oblock[0]), rle->oblen);
+      rle->outstream->write ((const char*)&(rle->oblock[0]), rle->oblen);
     }
 #endif  
 
@@ -416,7 +416,7 @@
 /* create new RLE struct, which writes to a specified stream */
 rle_out *
 #ifdef LIBPLOTTER
-_rle_init (FILE *fp, ostream *out, int bit_depth)
+_rle_init (FILE *fp, std::ostream *out, int bit_depth)
 #else
 #ifdef _HAVE_PROTOS
 _rle_init (FILE *fp, int bit_depth)
