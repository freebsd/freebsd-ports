--- bfd/elfnn-ia64.c.orig	2013-03-11 10:21:19.000000000 +0100
+++ bfd/elfnn-ia64.c	2013-03-11 10:21:43.000000000 +0100
@@ -1546,7 +1546,7 @@
     bfd_set_section_flags (abfd, ia64_info->root.sgot,
 			   SEC_SMALL_DATA | flags);
     /* The .got section is always aligned at 8 bytes.  */
-    bfd_set_section_alignment (abfd, ia64_info->root.sgot, 3);
+    (void)bfd_set_section_alignment (abfd, ia64_info->root.sgot, 3);
   }
 
   if (!get_pltoff (abfd, info, ia64_info))
