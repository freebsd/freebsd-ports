--- src/gifwrite.c.orig	2011-06-22 18:04:32 UTC
+++ src/gifwrite.c
@@ -25,7 +25,7 @@
 
 #include <gif_lib.h>
 
-int list_length( value list )
+static int list_length( value list )
 {
   CAMLparam1(list);
   CAMLlocal1(l);
@@ -52,7 +52,11 @@ ColorMapObject *ColorMapObject_val( valu
 fprintf(stderr, "Creating map with length = %d ...\n", len);
 fflush(stderr);
 */
+#if GIFLIB_MAJOR >= 5
+  cmapobj = GifMakeMapObject( len, NULL );
+#else
   cmapobj = MakeMapObject( len, NULL );
+#endif
   for(i=0; i< len; i++){
     cmapobj->Colors[i].Red   = Int_val(Field(Field(cmap,i),0));
     cmapobj->Colors[i].Green = Int_val(Field(Field(cmap,i),1));
@@ -68,7 +72,11 @@ value eGifOpenFileName( name )
 
   GifFileType *GifFileOut;
 
+#if GIFLIB_MAJOR >= 5
+  if ((GifFileOut = EGifOpenFileName( String_val( name ), 0, NULL) )== NULL) {
+#else
   if ((GifFileOut = EGifOpenFileName( String_val( name ), 0) )== NULL) {
+#endif
     failwith("EGifOpenFileName");
   }
   /* gcc -fwritable-strings is required to compile libungif */
@@ -133,7 +141,6 @@ value eGifPutLine( value oc, value buf )
 
   if ( EGifPutLine(GifFileOut, String_val(buf), GifFileOut->Image.Width) 
        == GIF_ERROR ){
-    PrintGifError ();
     failwith("EGifPutLine");
   }
   CAMLreturn(Val_unit);
