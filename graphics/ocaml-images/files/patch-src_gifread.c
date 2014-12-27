--- src/gifread.c.orig	2011-06-22 18:04:32 UTC
+++ src/gifread.c
@@ -140,7 +140,11 @@ value dGifOpenFileName( value name )
   GifFileType *GifFile;
   int i;
 
+#if GIFLIB_MAJOR >= 5
+  if((GifFile = DGifOpenFileName( String_val(name), NULL )) == NULL){
+#else
   if((GifFile = DGifOpenFileName( String_val(name) )) == NULL){
+#endif
     failwith("DGifOpenFileName");
   }
 
@@ -200,7 +204,6 @@ value dGifGetLine( value hdl )
 
   if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
