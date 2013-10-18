--- bfd/bfdio.c.orig
+++ bfd/bfdio.c
@@ -577,7 +577,7 @@
 {
   struct bfd_in_memory *bim = (struct bfd_in_memory *) abfd->iostream;
 
-  memset (statbuf, 0, sizeof (statbuf));
+  memset (statbuf, 0, sizeof (*statbuf));
   statbuf->st_size = bim->size;
 
   return 0;
