--- libpolyml/elfexport.h.orgi	2013-02-08 16:01:09.000000000 +0800
+++ libpolyml/elfexport.h	2013-02-08 16:01:43.000000000 +0800
@@ -37,7 +37,7 @@
 #define ElfXX_Sym   Elf64_Sym
 #define ElfXX_Ehdr  Elf64_Ehdr
 #define ElfXX_Shdr  Elf64_Shdr
-#define ELFXX_R_INFO(_y, _z)    ELF64_R_INFO(_y, _z)
+#define ELFXX_R_INFO(_y, _z)    ELF64_R_INFO((Elf64_Xword)(_y), _z)
 #define ELFXX_ST_INFO(_y, _z)   ELF64_ST_INFO(_y, _z)
 #define ELFCLASSXX      ELFCLASS64
 #else
