--- ./bfd/cpu-mips.c.orig	2010-11-17 09:32:42.000000000 +0000
+++ ./bfd/cpu-mips.c	2012-01-25 22:24:29.000000000 +0000
@@ -89,6 +89,7 @@
   I_mipsisa64,
   I_mipsisa64r2,
   I_sb1,
+  I_allegrex,
   I_loongson_2e,
   I_loongson_2f,
   I_loongson_3a,
@@ -129,6 +130,7 @@
   N (64, 64, bfd_mach_mipsisa64,  "mips:isa64",   FALSE, NN(I_mipsisa64)),
   N (64, 64, bfd_mach_mipsisa64r2,"mips:isa64r2", FALSE, NN(I_mipsisa64r2)),
   N (64, 64, bfd_mach_mips_sb1, "mips:sb1",       FALSE, NN(I_sb1)),
+  N (32, 32, bfd_mach_mips_allegrex, "mips:allegrex", FALSE, NN(I_allegrex)),
   N (64, 64, bfd_mach_mips_loongson_2e, "mips:loongson_2e",       FALSE, NN(I_loongson_2e)),
   N (64, 64, bfd_mach_mips_loongson_2f, "mips:loongson_2f",       FALSE, NN(I_loongson_2f)),
   N (64, 64, bfd_mach_mips_loongson_3a, "mips:loongson_3a",       FALSE, NN(I_loongson_3a)),
