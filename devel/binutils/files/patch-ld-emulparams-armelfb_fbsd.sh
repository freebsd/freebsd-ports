--- ld/emulparams/armelfb_fbsd.sh.orig	1970-01-01 00:21:38.000000000 +0000
+++ ld/emulparams/armelfb_fbsd.sh	1970-01-01 00:25:49.000000000 +0000
@@ -0,0 +1,2 @@
+. ${srcdir}/emulparams/armelf_fbsd.sh
+OUTPUT_FORMAT="elf32-bigarm"
