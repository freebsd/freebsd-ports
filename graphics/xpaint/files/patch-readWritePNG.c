--- rw/readWritePNG.c.orig	2005-03-20 21:15:34.000000000 +0100
+++ rw/readWritePNG.c	2010-03-29 16:48:36.000000000 +0200
@@ -51,7 +51,7 @@
     fread(header, 1, 8, fp);
     fclose(fp);
 
-    return png_check_sig( (unsigned char*) header, 8);
+    return !png_sig_cmp( (unsigned char*) header, 0, 8);
 }
 
 
