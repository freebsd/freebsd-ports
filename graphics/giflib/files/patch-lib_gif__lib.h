--- lib/gif_lib.h.orig	2016-04-02 15:35:30 UTC
+++ lib/gif_lib.h
@@ -244,9 +244,6 @@ extern ColorMapObject *GifUnionColorMap(
                                      GifPixelType ColorTransIn2[]);
 extern int GifBitSize(int n);
 
-extern void *
-reallocarray(void *optr, size_t nmemb, size_t size);
-
 /******************************************************************************
  Support for the in-core structures allocation (slurp mode).              
 ******************************************************************************/
