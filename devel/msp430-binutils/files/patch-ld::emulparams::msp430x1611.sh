--- ld/emulparams/msp430x1611.sh.orig	Tue Feb 24 16:15:02 2004
+++ ld/emulparams/msp430x1611.sh	Tue Feb 24 16:15:17 2004
@@ -0,0 +1,15 @@
+ARCH=msp:16
+MACHINE=
+SCRIPT_NAME=elf32msp430
+OUTPUT_FORMAT="elf32-msp430"
+MAXPAGESIZE=1
+EMBEDDED=yes
+TEMPLATE_NAME=generic
+
+ROM_START=0x4000
+ROM_SIZE=0xbfe0
+RAM_START=0x1100
+RAM_SIZE=0x27ff
+
+STACK=0x2800
+
