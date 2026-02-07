--- readpng.c.orig	2005-10-23 19:36:29 UTC
+++ readpng.c
@@ -57,7 +57,7 @@ TestPNG(char *file)  /* gets called a LO
     fread(header, 1, 8, fp);
     fclose(fp);
 
-    return png_check_sig(header, 8);
+    return !png_sig_cmp(header, 0, 8);
 }
 
 static void
