--- bfd/elfxx-mips.c.orig	2005-10-25 17:19:08.000000000 +0100
+++ bfd/elfxx-mips.c	2007-02-08 20:06:04.000000000 +0000
@@ -4666,6 +4666,9 @@
     case E_MIPS_MACH_SB1:
       return bfd_mach_mips_sb1;
 
+    case E_MIPS_MACH_ALLEGREX:
+      return bfd_mach_mips_allegrex;
+
     default:
       switch (flags & EF_MIPS_ARCH)
 	{
@@ -7950,6 +7953,10 @@
       val = E_MIPS_ARCH_64 | E_MIPS_MACH_SB1;
       break;
 
+    case bfd_mach_mips_allegrex:
+      val = E_MIPS_ARCH_2 | E_MIPS_MACH_ALLEGREX;
+      break;
+
     case bfd_mach_mipsisa32:
       val = E_MIPS_ARCH_32;
       break;
@@ -9648,6 +9655,7 @@
   /* MIPS II extensions.  */
   { bfd_mach_mips4000, bfd_mach_mips6000 },
   { bfd_mach_mipsisa32, bfd_mach_mips6000 },
+  { bfd_mach_mips_allegrex, bfd_mach_mips6000 },
 
   /* MIPS I extensions.  */
   { bfd_mach_mips6000, bfd_mach_mips3000 },
