--- readpng.c.orig	2005-10-23 21:36:29.000000000 +0200
+++ readpng.c	2010-03-29 14:14:22.000000000 +0200
@@ -57,7 +57,7 @@
     fread(header, 1, 8, fp);
     fclose(fp);
 
-    return png_check_sig(header, 8);
+    return !png_sig_cmp(header, 0, 8);
 }
 
 static void
