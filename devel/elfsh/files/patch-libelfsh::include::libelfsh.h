--- libelfsh/include/libelfsh.h	Thu Aug 21 04:11:03 2003
+++ libelfsh/include/libelfsh.h.patch	Fri Oct 10 14:33:43 2003
@@ -713,5 +713,17 @@
 int		elfsh_sync_sorted_symtab(elfshsect_t *sect);
 int		elfsh_sort_symtab(Elf32_Sym *symtab, int size, int type);
 
+#define R_386_NONE      0	/* No reloc */
+#define R_386_32        1	/* Direct 32 bit  */
+#define R_386_PC32      2	/* PC relative 32 bit */
+#define R_386_GOT32     3	/* 32 bit GOT entry */
+#define R_386_PLT32     4	/* 32 bit PLT address */
+#define R_386_COPY      5	/* Copy symbol at runtime */
+#define R_386_GLOB_DAT  6	/* Create GOT entry */
+#define R_386_JMP_SLOT  7	/* Create PLT entry */
+#define R_386_RELATIVE  8	/* Adjust by program base */
+#define R_386_GOTOFF    9	/* 32 bit offset to GOT */
+#define R_386_GOTPC     10	/* 32 bit PC relative offset to GOT */
+
 
 #endif /* __LIBELFSH_H_ */
