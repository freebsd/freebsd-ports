--- Imlib/load.c.orig	2004-09-21 02:23:20.000000000 +0200
+++ Imlib/load.c	2010-03-28 16:23:13.000000000 +0200
@@ -1619,7 +1619,7 @@
     return 0;
   fread(buf, 1, 8, f);
   rewind(f);
-  return (int)png_check_sig(buf, 8);
+  return (int)!png_sig_cmp(buf, 0, 8);
 #else
   return 0;
 #endif
