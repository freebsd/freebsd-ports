--- bfd/peicode.h.orig	2012-12-18 14:22:02.000000000 +0100
+++ bfd/peicode.h	2012-12-18 14:22:21.000000000 +0100
@@ -602,7 +602,7 @@
 
   bfd_set_section_flags (vars->abfd, sec, flags | extra_flags);
 
-  bfd_set_section_alignment (vars->abfd, sec, 2);
+  (void)bfd_set_section_alignment (vars->abfd, sec, 2);
 
   /* Check that we will not run out of space.  */
   BFD_ASSERT (vars->data + size < vars->bim->buffer + vars->bim->size);
