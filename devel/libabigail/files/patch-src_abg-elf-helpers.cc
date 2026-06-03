--- src/abg-elf-helpers.cc.orig	2025-01-13 11:40:45 UTC
+++ src/abg-elf-helpers.cc
@@ -167,8 +167,10 @@ e_machine_to_string(GElf_Half e_machine)
       return "elf-motorola-rce";
     case EM_ARM:
       return "elf-arm";
+#ifdef EM_FAKE_ALPHA
     case EM_FAKE_ALPHA:
       return "elf-digital-alpha";
+#endif
     case EM_SH:
       return "elf-hitachi-sh";
     case EM_SPARCV9:
@@ -292,8 +294,10 @@ e_machine_to_string(GElf_Half e_machine)
       return "elf-riscv";
 #endif
 
+#ifdef EM_NUM
     case EM_NUM:
       return "elf-last-arch-number";
+#endif
     case EM_ALPHA:
       return "elf-non-official-alpha";
     default:
