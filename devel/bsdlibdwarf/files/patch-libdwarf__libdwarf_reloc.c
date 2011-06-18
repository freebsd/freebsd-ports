--- ./libdwarf/libdwarf_reloc.c.orig	2010-10-08 22:26:23.000000000 +0200
+++ ./libdwarf/libdwarf_reloc.c	2011-06-18 15:30:24.000000000 +0200
@@ -30,6 +30,10 @@
 #define	R_MIPS_64	18
 #endif
 
+#ifndef R_MIPS_32
+#define R_MIPS_32 0
+#endif
+
 Dwarf_Unsigned
 _dwarf_get_reloc_type(Dwarf_P_Debug dbg, int is64)
 {
