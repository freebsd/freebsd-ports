--- protos.h.orig	2024-10-31 16:19:27 UTC
+++ protos.h
@@ -33,17 +33,17 @@
   unsigned char e_ident[EI_NIDENT];
   Elf32_Ehdr e32;
   Elf64_Ehdr e64;
-} Elf_Ehdr;
+} absElf_Ehdr;
 
 typedef union {
   Elf32_Shdr e32;
   Elf64_Shdr e64;
-} Elf_Shdr;
+} absElf_Shdr;
 
 typedef union {
   Elf32_Phdr e32;
   Elf64_Phdr e64;
-} Elf_Phdr;
+} absElf_Phdr;
 
 int is_e32(void);
 int swap_bytes(void);
@@ -70,12 +70,12 @@
 int killrpath(const char *filename);
 int chrpath(const char *filename, const char *newpath, int convert);
 
-char* read_section_names(int fd, Elf_Ehdr ehdr);
+char* read_section_names(int fd, absElf_Ehdr ehdr);
 char* get_section_name(int name_off, char* section_names);
 
-int elf_open(const char *filename, int flags, Elf_Ehdr *ehdr);
+int elf_open(const char *filename, int flags, absElf_Ehdr *ehdr);
 void elf_close(int fd);
-int elf_find_dynamic_section(int fd, Elf_Ehdr *ehdr, Elf_Phdr *phdr);
+int elf_find_dynamic_section(int fd, absElf_Ehdr *ehdr, absElf_Phdr *phdr);
 const char *elf_tagname(int tag);
 int elf_dynpath_tag(int tag);
 
