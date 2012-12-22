--- src/lib/embryo_float.c.orig	2012-11-12 14:59:38.000000000 +0100
+++ src/lib/embryo_float.c	2012-11-12 15:00:04.000000000 +0100
@@ -263,7 +263,6 @@
 	return 0;
      }
     if (ff == 10.0) f = log10f(f);
-    else if (ff == 2.0) f = log2f(f);
     else
      {
         tf = logf(ff);
