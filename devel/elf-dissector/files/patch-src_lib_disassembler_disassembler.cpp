--- src/lib/disassmbler/disassembler.cpp.orig	2021-07-21 03:44:26.000000000 -0700
+++ src/lib/disassmbler/disassembler.cpp	2022-10-25 07:11:53.794805000 -0700
@@ -127,7 +127,7 @@
     QString result;
     disassembler_ftype disassemble_fn;
     disassemble_info info;
-    INIT_DISASSEMBLE_INFO(info, &result, qstring_printf);
+    INIT_DISASSEMBLE_INFO(info, &result, qstring_printf, qstring_printf);
 
     info.application_data = this;
     info.flavour = bfd_target_elf_flavour;
