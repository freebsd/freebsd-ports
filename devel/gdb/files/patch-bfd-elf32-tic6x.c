--- bfd/elf32-tic6x.c.orig	2013-03-07 10:03:28.000000000 +0100
+++ bfd/elf32-tic6x.c	2013-03-07 10:08:19.000000000 +0100
@@ -3043,7 +3043,7 @@
       *secp = bfd_make_section_old_way (abfd, ".scommon");
       (*secp)->flags |= SEC_IS_COMMON;
       *valp = sym->st_size;
-      bfd_set_section_alignment (abfd, *secp, bfd_log2 (sym->st_value));
+      (void)bfd_set_section_alignment (abfd, *secp, bfd_log2 (sym->st_value));
       break;
     }
 
@@ -3319,8 +3319,6 @@
     {
       bfd_signed_vma *local_got;
       bfd_signed_vma *end_local_got;
-      char *local_tls_type;
-      bfd_vma *local_tlsdesc_gotent;
       bfd_size_type locsymcount;
       Elf_Internal_Shdr *symtab_hdr;
       asection *srel;
@@ -3361,8 +3359,7 @@
       end_local_got = local_got + locsymcount;
       s = htab->elf.sgot;
       srel = htab->elf.srelgot;
-      for (; local_got < end_local_got;
-	   ++local_got, ++local_tls_type, ++local_tlsdesc_gotent)
+      for (; local_got < end_local_got; ++local_got)
 	{
 	  if (*local_got > 0)
 	    {
