--- sim/msp430/interp.c.orig	2014-05-18 22:55:26.000000000 +0400
+++ sim/msp430/interp.c	2014-05-18 22:58:22.000000000 +0400
@@ -1880,18 +1880,18 @@
   storage_needed = bfd_get_symtab_upper_bound (abfd);
 
   if (storage_needed < 0)
-    return;
+    return 0;
 
   if (storage_needed == 0)
     {
-      return;
+      return 0;
     }
 
   symbol_table = (asymbol **) xmalloc (storage_needed);
   number_of_symbols = bfd_canonicalize_symtab (abfd, symbol_table);
 
   if (number_of_symbols < 0)
-    return;
+    return 0;
 
   for (i = 0; i < number_of_symbols; i++)
     {
