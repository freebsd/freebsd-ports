--- protos.h.orig	2013-11-24 08:30:01.000000000 +0100
+++ protos.h	2016-02-03 19:47:21.946096000 +0100
@@ -1,7 +1,14 @@
 #ifndef PROTOS_H
 #define PROTOS_H
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#else
 #include <byteswap.h>
+#endif
 #include <elf.h>
 #include "config.h"
 
@@ -14,6 +21,12 @@
 #error "Unknown word size (SIZEOF_VOID_P)!"
 #endif
 
+#if defined __FreeBSD__ || defined __DragonFly__
+#define Elf_Ehdr Elf__Ehdr
+#define Elf_Shdr Elf__Shdr
+#define Elf_Phdr Elf__Phdr
+#endif
+
 typedef union {
   unsigned char e_ident[EI_NIDENT];
   Elf32_Ehdr e32;
