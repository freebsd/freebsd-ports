--- src/gifwrite.c.orig	2011-06-22 20:04:32.000000000 +0200
+++ src/gifwrite.c	2012-11-07 22:32:25.000000000 +0100
@@ -25,7 +25,7 @@
 
 #include <gif_lib.h>
 
-int list_length( value list )
+static int list_length( value list )
 {
   CAMLparam1(list);
   CAMLlocal1(l);
@@ -133,7 +133,6 @@
 
   if ( EGifPutLine(GifFileOut, String_val(buf), GifFileOut->Image.Width) 
        == GIF_ERROR ){
-    PrintGifError ();
     failwith("EGifPutLine");
   }
   CAMLreturn(Val_unit);
