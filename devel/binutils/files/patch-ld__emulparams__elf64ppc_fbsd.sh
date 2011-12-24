--- ./ld/emulparams/elf64ppc_fbsd.sh.orig	2011-12-21 09:44:40.000000000 +0100
+++ ./ld/emulparams/elf64ppc_fbsd.sh	2011-12-21 09:44:40.000000000 +0100
@@ -0,0 +1,6 @@
+. ${srcdir}/emulparams/elf64ppc.sh
+. ${srcdir}/emulparams/elf_fbsd.sh
+
+OUTPUT_FORMAT="elf64-powerpc-freebsd"
+DEFAULT_PLT_STATIC_CHAIN=1
+
