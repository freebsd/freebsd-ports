--- binutils/readelf.c.orig	2013-06-23 18:48:14.000000000 -0700
+++ binutils/readelf.c	2013-06-23 18:48:36.000000000 -0700
@@ -9043,7 +9043,7 @@
 
   n = print_vma (si, DEC_5);
   if (n < 5)
-    fputs ("     " + n, stdout);
+    fputs (&"     "[n], stdout);
   printf (" %3lu: ", hn);
   print_vma (psym->st_value, LONG_HEX);
   putchar (' ');
