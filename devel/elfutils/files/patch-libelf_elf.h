--- libelf/elf.h.orig	2020-03-30 12:17:45 UTC
+++ libelf/elf.h
@@ -54,6 +54,7 @@ typedef uint64_t Elf64_Off;
 /* Type for section indices, which are 16-bit quantities.  */
 typedef uint16_t Elf32_Section;
 typedef uint16_t Elf64_Section;
+#define	LIBELF_ELF_SECTION_DEFINED	1
 
 /* Type for version symbol information.  */
 typedef Elf32_Half Elf32_Versym;
@@ -1145,6 +1146,7 @@ typedef struct
 	 on 64-bit platforms and vice versa.  */
     } a_un;
 } Elf64_auxv_t;
+#define	LIBELF_ELF_AUXV_T_DEFINED	1
 
 /* Legal values for a_type (entry type).  */
 
