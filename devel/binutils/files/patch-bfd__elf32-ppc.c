--- ./bfd/elf32-ppc.c.orig	2011-11-21 10:29:21.000000000 +0100
+++ ./bfd/elf32-ppc.c	2011-12-21 09:44:40.000000000 +0100
@@ -9127,6 +9127,24 @@
 
 #include "elf32-target.h"
 
+/* FreeBSD Target */
+
+#undef  TARGET_LITTLE_SYM
+#undef  TARGET_LITTLE_NAME
+
+#undef  TARGET_BIG_SYM
+#define TARGET_BIG_SYM  bfd_elf32_powerpc_freebsd_vec
+#undef  TARGET_BIG_NAME
+#define TARGET_BIG_NAME "elf32-powerpc-freebsd"
+
+#undef  ELF_OSABI
+#define ELF_OSABI	ELFOSABI_FREEBSD
+
+#undef  elf32_bed
+#define elf32_bed	elf32_powerpc_fbsd_bed
+
+#include "elf32-target.h"
+
 /* VxWorks Target */
 
 #undef TARGET_LITTLE_SYM
@@ -9137,6 +9155,8 @@
 #undef TARGET_BIG_NAME
 #define TARGET_BIG_NAME		"elf32-powerpc-vxworks"
 
+#undef  ELF_OSABI
+
 /* VxWorks uses the elf default section flags for .plt.  */
 static const struct bfd_elf_special_section *
 ppc_elf_vxworks_get_sec_type_attr (bfd *abfd ATTRIBUTE_UNUSED, asection *sec)
