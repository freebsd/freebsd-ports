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
 
@@ -161,7 +165,11 @@ value dGifCloseFile( value hdl )
      segmentation faults */
   ((GifFileType *)hdl)->Image.ColorMap = NULL; 
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  DGifCloseFile( (GifFileType *) hdl, NULL );
+#else
   DGifCloseFile( (GifFileType *) hdl );
+#endif
   CAMLreturn(Val_unit);
 }
 
@@ -200,7 +208,6 @@ value dGifGetLine( value hdl )
 
   if( DGifGetLine(GifFile, String_val(buf), GifFile->Image.Width ) 
       == GIF_ERROR ){
-    PrintGifError ();
     failwith("DGifGetLine");
   }
   CAMLreturn(buf);
