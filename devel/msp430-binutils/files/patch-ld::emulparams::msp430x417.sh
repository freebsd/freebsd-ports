--- ld/emulparams/msp430x417.sh.orig	Mon Mar  1 16:23:57 2004
+++ ld/emulparams/msp430x417.sh	Mon Mar  1 16:24:11 2004
@@ -0,0 +1,15 @@
+ARCH=msp:41
+MACHINE=
+SCRIPT_NAME=elf32msp430
+OUTPUT_FORMAT="elf32-msp430"
+MAXPAGESIZE=1
+EMBEDDED=yes
+TEMPLATE_NAME=generic
+
+ROM_START=0x8000
+ROM_SIZE=0x7fe0
+RAM_START=0x0200
+RAM_SIZE=1024
+
+STACK=0x600
+
