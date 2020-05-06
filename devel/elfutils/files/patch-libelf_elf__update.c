--- libelf/elf_update.c.orig	2020-03-30 12:17:45 UTC
+++ libelf/elf_update.c
@@ -106,9 +106,13 @@ write_file (Elf *elf, int64_t size, int change_bo, siz
 	  if (elf->cmd == ELF_C_RDWR_MMAP
 	      && (size_t) size > elf->maximum_size)
 	    {
-	      if (mremap (elf->map_address, elf->maximum_size,
-			  size, 0) == MAP_FAILED)
+	      if (munmap (elf->map_address, elf->maximum_size) != 0 ||
+			  mmap (elf->map_address, size, PROT_READ | PROT_WRITE,
+			  MAP_SHARED | MAP_FIXED | MAP_EXCL, elf->fildes,
+			  0) == MAP_FAILED)
 		{
+		  elf->map_address = NULL;
+		  elf->flags &= ~ELF_F_MMAPPED;
 		  __libelf_seterrno (ELF_E_WRITE_ERROR);
 		  return -1;
 		}
