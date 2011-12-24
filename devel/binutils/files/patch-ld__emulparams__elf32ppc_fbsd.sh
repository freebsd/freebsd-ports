--- ./ld/emulparams/elf32ppc_fbsd.sh.orig	2002-02-18 10:38:01.000000000 +0100
+++ ./ld/emulparams/elf32ppc_fbsd.sh	2011-12-21 09:44:40.000000000 +0100
@@ -1,2 +1,5 @@
 . ${srcdir}/emulparams/elf32ppc.sh
 . ${srcdir}/emulparams/elf_fbsd.sh
+
+OUTPUT_FORMAT="elf32-powerpc-freebsd"
+
