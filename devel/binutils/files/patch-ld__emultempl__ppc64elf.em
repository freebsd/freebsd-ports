--- ./ld/emultempl/ppc64elf.em.orig	2011-11-21 10:29:39.000000000 +0100
+++ ./ld/emultempl/ppc64elf.em	2011-12-21 09:44:40.000000000 +0100
@@ -62,7 +62,7 @@
 static int no_toc_sort = 0;
 
 /* Set if PLT call stubs should load r11.  */
-static int plt_static_chain = 0;
+static int plt_static_chain = ${DEFAULT_PLT_STATIC_CHAIN-0};
 
 /* Whether to emit symbols for stubs.  */
 static int emit_stub_syms = -1;
