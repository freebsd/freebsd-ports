--- ./ld/emulparams/elf_mipsallegrexel_psp.sh.orig	2012-01-21 13:31:35.000000000 +0000
+++ ./ld/emulparams/elf_mipsallegrexel_psp.sh	2012-01-21 13:31:35.000000000 +0000
@@ -0,0 +1,22 @@
+# Based off of the default elf32 MIPS target.  However, we use a seperate
+# script template because the PSP architecture defines sections that normally
+# cannot be overriden here and would normally get absorbed (i.e.
+# .rodata.sceModuleInfo would be absorbed into .rodata).
+
+EMBEDDED=yes
+. ${srcdir}/emulparams/elf32lmip.sh
+unset NONPAGED_TEXT_START_ADDR
+unset SHLIB_TEXT_START_ADDR
+unset COMMONPAGESIZE
+
+SCRIPT_NAME=elf_psp
+TEXT_START_ADDR=0x08900000
+MAXPAGESIZE=256
+ARCH="mips:allegrex"
+MACHINE=
+TEMPLATE_NAME=elf32
+GENERATE_SHLIB_SCRIPT=yes
+DYNAMIC_LINK=FALSE
+
+# Discard the .comment and .pdr sections.
+OTHER_SECTIONS="/DISCARD/ : { *(.comment) *(.pdr) }"
