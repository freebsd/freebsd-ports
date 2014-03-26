--- src/gifread.c.orig	2012-11-07 22:33:55.000000000 +0100
+++ src/gifread.c	2012-11-07 22:34:04.000000000 +0100
@@ -200,7 +200,6 @@
 
   if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
