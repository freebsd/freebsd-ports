--- archivers/zip.c.orig	2017-03-03 22:21:13 UTC
+++ archivers/zip.c
@@ -327,7 +327,8 @@ static int ZIP_seek(fvoid *opaque, PHYSF
                 return(0);
 
             inflateEnd(&finfo->stream);
-            memcpy(&finfo->stream, &str, sizeof (z_stream));
+            inflateCopy(&finfo->stream, &str);
+            inflateEnd(&str);
             finfo->uncompressed_position = finfo->compressed_position = 0;
         } /* if */
 
