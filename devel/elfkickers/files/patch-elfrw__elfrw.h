--- ./elfrw/elfrw.h.orig	2011-05-31 01:47:08.000000000 +0200
+++ ./elfrw/elfrw.h	2011-06-08 12:16:37.000000000 +0200
@@ -10,6 +10,24 @@
 #include <stdio.h>
 #include <elf.h>
 
+#ifdef __FreeBSD__
+typedef uint16_t Elf64_Section;
+
+#define PT_GNU_STACK	0x6474e551
+#define PT_GNU_RELRO	0x6474e552
+
+#if  __FreeBSD_version < 700022
+#define SHT_GNU_HASH	0x6ffffff6
+#define EM_CRIS		76
+#define EM_M32R		88
+#define EM_MN10300	89
+#endif
+
+#define ELFCLASSNUM 3
+#define ELFDATANUM  3
+#define EV_NUM      2
+#endif
+
 /*
  * The initialization functions. Call one of these to set the flavor
  * of ELF structures to translate to and from. The library can be
