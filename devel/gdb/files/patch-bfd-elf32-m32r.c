--- bfd/elf32-m32r.c.orig	2013-03-07 09:57:30.000000000 +0100
+++ bfd/elf32-m32r.c	2013-03-07 09:57:53.000000000 +0100
@@ -1390,7 +1390,7 @@
 						  flags);
 	  if (s == NULL)
 	    return FALSE;
-	  bfd_set_section_alignment (abfd, s, 2);
+	  (void)bfd_set_section_alignment (abfd, s, 2);
 	}
 
       bh = bfd_link_hash_lookup (info->hash, "_SDA_BASE_",
