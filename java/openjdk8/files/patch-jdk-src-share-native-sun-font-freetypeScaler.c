--- jdk/src/share/native/sun/font/freetypeScaler.c
+++ jdk/src/share/native/sun/font/freetypeScaler.c
@@ -60,6 +60,7 @@
     JNIEnv* env;
     FT_Library library;
     FT_Face face;
+    FT_Stream faceStream;
     jobject font2D;
     jobject directBuffer;
 
@@ -107,15 +108,10 @@
     if (scalerInfo == NULL)
         return;
 
-    //apparently Done_Face will only close the stream
-    // but will not relase the memory of stream structure.
-    // We need to free it explicitly to avoid leak.
-    //Direct access to the stream field might be not ideal solution as
-    // it is considred to be "private".
-    //Alternatively we could have stored pointer to the structure
-    // in the scalerInfo but this will increase size of the structure
-    // for no good reason
-    stream = scalerInfo->face->stream;
+    // FT_Done_Face always closes the stream, but only frees the memory
+    // of the data structure if it was internally allocated by FT.
+    // We hold on to a pointer to the stream structure if we provide it
+    // ourselves, so that we can free it here.
 
     FT_Done_Face(scalerInfo->face);
     FT_Done_FreeType(scalerInfo->library);
@@ -128,8 +124,8 @@
         free(scalerInfo->fontData);
     }
 
-   if (stream != NULL) {
-        free(stream);
+   if (scalerInfo->faceStream != NULL) {
+        free(scalerInfo->faceStream);
    }
 
     free(scalerInfo);
@@ -302,6 +298,10 @@
                                          &ft_open_args,
                                          indexInCollection,
                                          &scalerInfo->face);
+
+                    if (!error) {
+                        scalerInfo->faceStream = ftstream;
+                    }
                 }
                 if (error || scalerInfo->directBuffer == NULL) {
                     free(ftstream);
