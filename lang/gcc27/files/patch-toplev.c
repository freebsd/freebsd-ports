--- toplev.c.orig	Fri Oct 20 14:56:35 1995
+++ toplev.c	Mon Mar 20 13:29:12 2000
@@ -521,6 +521,10 @@
 /* Tag all structures with __attribute__(packed) */
 int flag_pack_struct = 0;
 
+/* Nonzero means that -Wformat accepts certain system-dependent formats.  */
+
+int flag_format_extensions = 0;
+
 /* Table of language-independent -f options.
    STRING is the option name.  VARIABLE is the address of the variable.
    ON_VALUE is the value to store in VARIABLE
@@ -567,6 +571,7 @@
   {"verbose-asm", &flag_verbose_asm, 1},
   {"gnu-linker", &flag_gnu_linker, 1},
   {"pack-struct", &flag_pack_struct, 1},
+  {"format-extensions", &flag_format_extensions, 1},
   {"bytecode", &output_bytecode, 1}
 };
 
