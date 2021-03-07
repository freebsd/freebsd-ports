--- src/abg-elf-helpers.cc.orig	2021-03-07 00:14:31 UTC
+++ src/abg-elf-helpers.cc
@@ -178,8 +178,10 @@ e_machine_to_string(GElf_Half e_machine)
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
@@ -298,8 +300,10 @@ e_machine_to_string(GElf_Half e_machine)
       return "elf-tilera-tilegx";
 #endif
 
+#ifdef EM_NUM
     case EM_NUM:
       return "elf-last-arch-number";
+#endif
     case EM_ALPHA:
       return "elf-non-official-alpha";
     default:
