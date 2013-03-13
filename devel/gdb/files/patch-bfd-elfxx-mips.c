--- bfd/elfxx-mips.c.orig	2013-03-07 10:12:06.000000000 +0100
+++ bfd/elfxx-mips.c	2013-03-07 10:13:30.000000000 +0100
@@ -7292,20 +7292,20 @@
       /* Change alignments of some sections.  */
       s = bfd_get_linker_section (abfd, ".hash");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynsym");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynstr");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       /* ??? */
       s = bfd_get_section_by_name (abfd, ".reginfo");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
       s = bfd_get_linker_section (abfd, ".dynamic");
       if (s != NULL)
-	bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
+	(void)bfd_set_section_alignment (abfd, s, MIPS_ELF_LOG_FILE_ALIGN (abfd));
     }
 
   if (!info->shared)
