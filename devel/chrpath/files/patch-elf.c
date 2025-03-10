--- elf.c.orig	2025-02-22 12:27:36 UTC
+++ elf.c
@@ -48,7 +48,7 @@
 }
 
 int
-elf_open(const char *filename, int flags, Elf_Ehdr *ehdr)
+elf_open(const char *filename, int flags, absElf_Ehdr *ehdr)
 {
    int fd;
    size_t sz_ehdr;
@@ -105,7 +105,7 @@
 }
 
 int
-elf_find_dynamic_section(int fd, Elf_Ehdr *ehdr, Elf_Phdr *phdr)
+elf_find_dynamic_section(int fd, absElf_Ehdr *ehdr, absElf_Phdr *phdr)
 {
   int i;
   if (lseek(fd, EHDR_PWU(e_phoff), SEEK_SET) == -1)
