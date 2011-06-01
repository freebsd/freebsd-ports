--- ./elfrw/elfrw.h.orig	2011-05-31 01:47:08.000000000 +0200
+++ ./elfrw/elfrw.h	2011-06-01 17:13:31.000000000 +0200
@@ -10,6 +10,17 @@
 #include <stdio.h>
 #include <elf.h>
 
+#ifdef __FreeBSD__
+typedef uint16_t Elf64_Section;
+
+#define PT_GNU_STACK	0x6474e551
+#define PT_GNU_RELRO	0x6474e552
+
+#define ELFCLASSNUM 3
+#define ELFDATANUM  3
+#define EV_NUM      2
+#endif
+
 /*
  * The initialization functions. Call one of these to set the flavor
  * of ELF structures to translate to and from. The library can be
