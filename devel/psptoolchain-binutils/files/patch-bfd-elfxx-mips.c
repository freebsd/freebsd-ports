--- ./bfd/elfxx-mips.c.orig	2011-11-21 09:29:27.000000000 +0000
+++ ./bfd/elfxx-mips.c	2012-01-21 13:31:35.000000000 +0000
@@ -6173,14 +6173,19 @@
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
@@ -10882,6 +10887,10 @@
       val = E_MIPS_ARCH_64 | E_MIPS_MACH_SB1;
       break;
 
+    case bfd_mach_mips_allegrex:
+      val = E_MIPS_ARCH_2 | E_MIPS_MACH_ALLEGREX;
+      break;
+
     case bfd_mach_mips_loongson_3a:
       val = E_MIPS_ARCH_64 | E_MIPS_MACH_LS3A;
       break;
@@ -13544,6 +13553,7 @@
   /* MIPS II extensions.  */
   { bfd_mach_mips4000, bfd_mach_mips6000 },
   { bfd_mach_mipsisa32, bfd_mach_mips6000 },
+  { bfd_mach_mips_allegrex, bfd_mach_mips6000 },
 
   /* MIPS I extensions.  */
   { bfd_mach_mips6000, bfd_mach_mips3000 },
