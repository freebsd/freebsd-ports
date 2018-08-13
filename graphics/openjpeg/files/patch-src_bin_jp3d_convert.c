--- src/bin/jp3d/convert.c.orig	2018-08-02 17:40:37 UTC
+++ src/bin/jp3d/convert.c
@@ -297,7 +297,7 @@ opj_volume_t* pgxtovolume(char *relpath,
         fprintf(stdout, "[INFO] Loading %s \n", pgxfiles[pos]);
 
         fseek(f, 0, SEEK_SET);
-        fscanf(f, "PG%[ \t]%c%c%[ \t+-]%d%[ \t]%d%[ \t]%d", temp, &endian1, &endian2,
+        fscanf(f, "PG%31[ \t]%c%c%31[ \t+-]%d%31[ \t]%d%31[ \t]%d", temp, &endian1, &endian2
                signtmp, &prec, temp, &w, temp, &h);
 
         i = 0;
