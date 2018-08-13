--- src/bin/jpwl/convert.c.orig	2018-08-02 17:47:37 UTC
+++ src/bin/jpwl/convert.c
@@ -1348,7 +1348,7 @@ opj_image_t* pgxtoimage(const char *file
     }
 
     fseek(f, 0, SEEK_SET);
-    if (fscanf(f, "PG%[ \t]%c%c%[ \t+-]%d%[ \t]%d%[ \t]%d", temp, &endian1,
+    if (fscanf(f, "PG%31[ \t]%c%c%31[ \t+-]%d%31[ \t]%d%31[ \t]%d", temp, &endian1,
                &endian2, signtmp, &prec, temp, &w, temp, &h) != 9) {
         fprintf(stderr,
                 "ERROR: Failed to read the right number of element from the fscanf() function!\n");
