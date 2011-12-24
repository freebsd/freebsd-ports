--- ./bfd/elf64-ppc.c.orig	2011-11-21 10:29:24.000000000 +0100
+++ ./bfd/elf64-ppc.c	2011-12-21 09:44:40.000000000 +0100
@@ -13897,3 +13897,22 @@
 }
 
 #include "elf64-target.h"
+
+/* FreeBSD support */
+
+#undef  TARGET_LITTLE_SYM
+#undef  TARGET_LITTLE_NAME
+
+#undef  TARGET_BIG_SYM
+#define TARGET_BIG_SYM	bfd_elf64_powerpc_freebsd_vec
+#undef  TARGET_BIG_NAME
+#define TARGET_BIG_NAME "elf64-powerpc-freebsd"
+
+#undef  ELF_OSABI
+#define	ELF_OSABI       ELFOSABI_FREEBSD
+
+#undef  elf64_bed
+#define elf64_bed	elf64_powerpc_fbsd_bed
+
+#include "elf64-target.h"
+
