--- rwimg/rwgif.c.orig	2006-12-10 17:59:54 UTC
+++ rwimg/rwgif.c
@@ -54,7 +54,11 @@ open_gif_file (const char *filename, int
     
     assert(data != 0);
     
+#if GIFLIB_MAJOR >= 5
+    data->file = DGifOpenFileName(filename, NULL);
+#else
     data->file = DGifOpenFileName(filename);
+#endif
     
     assert(data->file !=0);
         
@@ -137,7 +141,11 @@ open_gif_file (const char *filename, int
     }
     free(buffer);
     
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    assert(DGifCloseFile(data->file, NULL) == GIF_OK);
+#else
     assert(DGifCloseFile(data->file) == GIF_OK);
+#endif
     
     return data;
 }
