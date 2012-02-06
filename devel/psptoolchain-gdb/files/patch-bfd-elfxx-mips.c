--- ./bfd/elfxx-mips.c.orig	2011-01-22 10:16:28.000000000 +0000
+++ ./bfd/elfxx-mips.c	2012-01-25 22:24:29.000000000 +0000
@@ -5940,14 +5940,19 @@
     case E_MIPS_MACH_SB1:
       return bfd_mach_mips_sb1;
 
+    case E_MIPS_MACH_ALLEGREX:
+      return bfd_mach_mips_allegrex;
+
     case E_MIPS_MACH_LS2E:
       return bfd_mach_mips_loongson_2e;
 
     case E_MIPS_MACH_LS2F:
       return bfd_mach_mips_loongson_2f;
 
+    /*
     case E_MIPS_MACH_LS3A:
       return bfd_mach_mips_loongson_3a;
+    */
 
     case E_MIPS_MACH_OCTEON:
       return bfd_mach_mips_octeon;
@@ -12311,6 +12316,7 @@
   /* MIPS II extensions.  */
   { bfd_mach_mips4000, bfd_mach_mips6000 },
   { bfd_mach_mipsisa32, bfd_mach_mips6000 },
+  { bfd_mach_mips_allegrex, bfd_mach_mips6000 },
 
   /* MIPS I extensions.  */
   { bfd_mach_mips6000, bfd_mach_mips3000 },
