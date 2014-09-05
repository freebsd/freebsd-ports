--- ld/emulparams/armelf_fbsd.sh.orig	1970-01-01 00:21:26.000000000 +0000
+++ ld/emulparams/armelf_fbsd.sh	1970-01-01 00:25:53.000000000 +0000
@@ -1,3 +1,8 @@
 . ${srcdir}/emulparams/armelf.sh
 . ${srcdir}/emulparams/elf_fbsd.sh
 TARGET2_TYPE=got-rel
+MAXPAGESIZE="CONSTANT (MAXPAGESIZE)"
+GENERATE_PIE_SCRIPT=yes
+
+unset STACK_ADDR
+unset EMBEDDED
