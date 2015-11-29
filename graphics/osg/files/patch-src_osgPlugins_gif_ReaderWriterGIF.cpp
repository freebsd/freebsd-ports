--- src/osgPlugins/gif/ReaderWriterGIF.cpp.orig	2013-06-03 14:04:02 UTC
+++ src/osgPlugins/gif/ReaderWriterGIF.cpp
@@ -561,7 +561,11 @@ GifImageStream** obj)
     *width_ret = giffile->SWidth;
     *height_ret = giffile->SHeight;
     *numComponents_ret = 4;
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    DGifCloseFile(giffile, NULL);
+#else
     DGifCloseFile(giffile);
+#endif
     return buffer;
 }
 
