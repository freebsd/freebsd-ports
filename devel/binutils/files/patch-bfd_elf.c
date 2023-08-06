--- bfd/elf.c.orig	2023-01-14 00:00:00 UTC
+++ bfd/elf.c
@@ -3870,21 +3870,23 @@ assign_section_numbers (bfd *abfd, struct bfd_link_inf
 	{
 	case SHT_REL:
 	case SHT_RELA:
-	  /* A reloc section which we are treating as a normal BFD
-	     section.  sh_link is the section index of the symbol
-	     table.  sh_info is the section index of the section to
-	     which the relocation entries apply.  We assume that an
-	     allocated reloc section uses the dynamic symbol table
-	     if there is one.  Otherwise we guess the normal symbol
-	     table.  FIXME: How can we be sure?  */
-	  if (d->this_hdr.sh_link == 0 && (sec->flags & SEC_ALLOC) != 0)
+	  /* sh_link is the section index of the symbol table.
+	     sh_info is the section index of the section to which the
+	     relocation entries apply.  */
+	  if (d->this_hdr.sh_link == 0)
 	    {
-	      s = bfd_get_section_by_name (abfd, ".dynsym");
-	      if (s != NULL)
-		d->this_hdr.sh_link = elf_section_data (s)->this_idx;
+	      /* FIXME maybe: If this is a reloc section which we are
+		 treating as a normal section then we likely should
+		 not be assuming its sh_link is .dynsym or .symtab.  */
+	      if ((sec->flags & SEC_ALLOC) != 0)
+		{
+		  s = bfd_get_section_by_name (abfd, ".dynsym");
+		  if (s != NULL)
+		    d->this_hdr.sh_link = elf_section_data (s)->this_idx;
+		}
+	      else
+		d->this_hdr.sh_link = elf_onesymtab (abfd);
 	    }
-	  if (d->this_hdr.sh_link == 0)
-	    d->this_hdr.sh_link = elf_onesymtab (abfd);
 
 	  s = elf_get_reloc_section (sec);
 	  if (s != NULL)
