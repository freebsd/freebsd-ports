--- bfd/elfxx-sparc.c.orig	2013-11-08 11:13:48.000000000 +0100
+++ bfd/elfxx-sparc.c	2014-10-10 16:30:23.316125000 +0200
@@ -2942,12 +2942,14 @@
   Elf_Internal_Rela *relend;
   int num_relocs;
   bfd_boolean is_vxworks_tls;
+  const struct elf_backend_data *bed;
 
   htab = _bfd_sparc_elf_hash_table (info);
   BFD_ASSERT (htab != NULL);
   symtab_hdr = &elf_symtab_hdr (input_bfd);
   sym_hashes = elf_sym_hashes (input_bfd);
   local_got_offsets = elf_local_got_offsets (input_bfd);
+  bed = get_elf_backend_data (output_bfd);
 
   if (elf_hash_table (info)->hgot == NULL)
     got_base = 0;
@@ -3528,6 +3530,8 @@
 			      bfd_set_error (bfd_error_bad_value);
 			      return FALSE;
 			    }
+			  if (bed->elf_osabi == ELFOSABI_FREEBSD)
+			    outrel.r_addend -= osec->vma;
 			}
 
 		      outrel.r_info = SPARC_ELF_R_INFO (htab, rel, indx,
