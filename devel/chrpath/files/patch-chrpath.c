--- chrpath.c.orig	2025-02-22 12:22:26 UTC
+++ chrpath.c
@@ -60,9 +60,9 @@
  * Reads the section names table from an ELF file into memory
  */
 char*
-read_section_names(int fd, Elf_Ehdr ehdr)
+read_section_names(int fd, absElf_Ehdr ehdr)
 {
-  Elf_Shdr shdr;
+  absElf_Shdr shdr;
 
   const size_t sz_shdr = is_e32() ? sizeof(Elf32_Shdr) : sizeof(Elf64_Shdr);
   const size_t sh_off = EHDRWU(e_shoff);
@@ -122,10 +122,10 @@
 chrpath(const char *filename, const char *newpath, int convert)
 {
   int fd;
-  Elf_Ehdr ehdr;
+  absElf_Ehdr ehdr;
   int i;
-  Elf_Phdr phdr;
-  Elf_Shdr shdr;
+  absElf_Phdr phdr;
+  absElf_Shdr shdr;
   void *dyns;
   int rpathoff;
   char * strtab;
