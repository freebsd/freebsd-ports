--- bfd/cpu-mips.c.orig	2005-05-04 16:53:06.000000000 +0100
+++ bfd/cpu-mips.c	2007-02-08 20:06:04.000000000 +0000
@@ -86,6 +86,7 @@
   I_mipsisa64,
   I_mipsisa64r2,
   I_sb1,
+  I_allegrex,
 };
 
 #define NN(index) (&arch_info_struct[(index) + 1])
@@ -118,7 +119,8 @@
   N (32, 32, bfd_mach_mipsisa32r2,"mips:isa32r2", FALSE, NN(I_mipsisa32r2)),
   N (64, 64, bfd_mach_mipsisa64,  "mips:isa64",   FALSE, NN(I_mipsisa64)),
   N (64, 64, bfd_mach_mipsisa64r2,"mips:isa64r2", FALSE, NN(I_mipsisa64r2)),
-  N (64, 64, bfd_mach_mips_sb1, "mips:sb1",       FALSE, 0),
+  N (64, 64, bfd_mach_mips_sb1, "mips:sb1",       FALSE, NN(I_sb1)),
+  N (32, 32, bfd_mach_mips_allegrex, "mips:allegrex", FALSE, 0),
 };
 
 /* The default architecture is mips:3000, but with a machine number of
