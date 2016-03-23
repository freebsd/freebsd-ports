--- plugins/tiff_stream.h.orig	2016-02-04 15:57:56 UTC
+++ plugins/tiff_stream.h
@@ -102,7 +102,8 @@ const CImg<T>& save_tiff(std::ostream *t
   TIFF *tif = TIFFStreamOpen("MemTiff", tiffOutStream);
   if (tif)
     {
-      cimg_forZ(*this,z) get_slice(z)._save_tiff(tif,z,compression_type,0,0);
+/* Upstream fix for issue #42 */
+      cimg_forZ(*this,z) get_slice(z)._save_tiff(tif,z,z,compression_type,0,0);
       tiffOutStream->flush();
       TIFFClose(tif);
     }
