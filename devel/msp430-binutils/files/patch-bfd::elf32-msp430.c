--- bfd/elf32-msp430.c	2002-12-31 03:25:10.000000000 +0800
+++ bfd/elf32-msp430.c	2003-08-06 01:51:10.000000000 +0800
@@ -548,40 +548,36 @@
   unsigned long val;
 
   switch (bfd_get_mach (abfd))
     {
     default:
-    case bfd_mach_msp12:
-      val = E_MSP430_MACH_MSP430x12;
-      break;
-
     case bfd_mach_msp110:
       val = E_MSP430_MACH_MSP430x11x1;
       break;
 
     case bfd_mach_msp11:
       val = E_MSP430_MACH_MSP430x11;
       break;
 
+    case bfd_mach_msp12:
+      val = E_MSP430_MACH_MSP430x12;
+      break;
+
     case bfd_mach_msp13:
       val = E_MSP430_MACH_MSP430x13;
       break;
 
     case bfd_mach_msp14:
       val = E_MSP430_MACH_MSP430x14;
       break;
 
-    case bfd_mach_msp41:
-      val = E_MSP430_MACH_MSP430x41;
-      break;
-
-    case bfd_mach_msp43:
-      val = E_MSP430_MACH_MSP430x43;
+    case bfd_mach_msp15:
+      val = E_MSP430_MACH_MSP430x15;
       break;
 
-    case bfd_mach_msp44:
-      val = E_MSP430_MACH_MSP430x44;
+    case bfd_mach_msp16:
+      val = E_MSP430_MACH_MSP430x16;
       break;
 
     case bfd_mach_msp31:
       val = E_MSP430_MACH_MSP430x31;
       break;
@@ -592,16 +588,24 @@
 
     case bfd_mach_msp33:
       val = E_MSP430_MACH_MSP430x33;
       break;
 
-    case bfd_mach_msp15:
-      val = E_MSP430_MACH_MSP430x15;
+    case bfd_mach_msp41:
+      val = E_MSP430_MACH_MSP430x41;
       break;
 
-    case bfd_mach_msp16:
-      val = E_MSP430_MACH_MSP430x16;
+    case bfd_mach_msp42:
+      val = E_MSP430_MACH_MSP430x42;
+      break;
+
+    case bfd_mach_msp43:
+      val = E_MSP430_MACH_MSP430x43;
+      break;
+
+    case bfd_mach_msp44:
+      val = E_MSP430_MACH_MSP430x44;
       break;
     }
 
   elf_elfheader (abfd)->e_machine = EM_MSP430;
   elf_elfheader (abfd)->e_flags &= ~EF_MSP430_MACH;
@@ -622,34 +626,38 @@
       int e_mach = elf_elfheader (abfd)->e_flags & EF_MSP430_MACH;
 
       switch (e_mach)
 	{
 	default:
-	case E_MSP430_MACH_MSP430x12:
-	  e_set = bfd_mach_msp12;
-	  break;
-
 	case E_MSP430_MACH_MSP430x11:
 	  e_set = bfd_mach_msp11;
 	  break;
 
 	case E_MSP430_MACH_MSP430x11x1:
 	  e_set = bfd_mach_msp110;
 	  break;
 
+	case E_MSP430_MACH_MSP430x12:
+	  e_set = bfd_mach_msp12;
+	  break;
+
 	case E_MSP430_MACH_MSP430x13:
 	  e_set = bfd_mach_msp13;
 	  break;
 
 	case E_MSP430_MACH_MSP430x14:
 	  e_set = bfd_mach_msp14;
 	  break;
 
-	case E_MSP430_MACH_MSP430x41:
-	  e_set = bfd_mach_msp41;
+	case E_MSP430_MACH_MSP430x15:
+	  e_set = bfd_mach_msp15;
 	  break;
 
+	case E_MSP430_MACH_MSP430x16:
+	  e_set = bfd_mach_msp16;
+	  break;
+
 	case E_MSP430_MACH_MSP430x31:
 	  e_set = bfd_mach_msp31;
 	  break;
 
 	case E_MSP430_MACH_MSP430x32:
@@ -658,24 +666,24 @@
 
 	case E_MSP430_MACH_MSP430x33:
 	  e_set = bfd_mach_msp33;
 	  break;
 
-	case E_MSP430_MACH_MSP430x43:
-	  e_set = bfd_mach_msp43;
+	case E_MSP430_MACH_MSP430x41:
+	  e_set = bfd_mach_msp41;
 	  break;
 
-	case E_MSP430_MACH_MSP430x44:
-	  e_set = bfd_mach_msp44;
+	case E_MSP430_MACH_MSP430x42:
+	  e_set = bfd_mach_msp42;
 	  break;
 
-	case E_MSP430_MACH_MSP430x15:
-	  e_set = bfd_mach_msp15;
+	case E_MSP430_MACH_MSP430x43:
+	  e_set = bfd_mach_msp43;
 	  break;
 
-	case E_MSP430_MACH_MSP430x16:
-	  e_set = bfd_mach_msp16;
+	case E_MSP430_MACH_MSP430x44:
+	  e_set = bfd_mach_msp44;
 	  break;
 	}
     }
 
   return bfd_default_set_arch_mach (abfd, bfd_arch_msp430, e_set);
