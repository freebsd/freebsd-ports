--- bfd/cpu-msp430.c	2002-12-31 03:25:10.000000000 +0800
+++ bfd/cpu-msp430.c	2003-08-06 01:51:10.000000000 +0800
@@ -44,46 +44,48 @@
 static const bfd_arch_info_type arch_info_struct[] =
 {
   /* msp430x11x.  */
   N (16, bfd_mach_msp11, "msp:11", FALSE, & arch_info_struct[1]),
 
+  /* msp430x11x1.  */
+  N (16, bfd_mach_msp110, "msp:110", FALSE, & arch_info_struct[2]),
+
   /* msp430x12x.  */
-  N (16, bfd_mach_msp12, "msp:12", FALSE, & arch_info_struct[2]),
+  N (16, bfd_mach_msp12, "msp:12", FALSE, & arch_info_struct[3]),
 
   /* msp430x13x.  */
-  N (16, bfd_mach_msp13, "msp:13", FALSE, & arch_info_struct[3]),
+  N (16, bfd_mach_msp13, "msp:13", FALSE, & arch_info_struct[4]),
 
   /* msp430x14x.  */
-  N (16, bfd_mach_msp14, "msp:14", FALSE, & arch_info_struct[4]),
+  N (16, bfd_mach_msp14, "msp:14", FALSE, & arch_info_struct[5]),
+
+  /* msp430x15x.  */
+  N (16, bfd_mach_msp15, "msp:15", FALSE, & arch_info_struct[6]),
+  
+  /* msp430x16x.  */
+  N (16, bfd_mach_msp16, "msp:16", FALSE, & arch_info_struct[7]),
 
   /* msp430x31x.  */
-  N (16, bfd_mach_msp31, "msp:31", FALSE, & arch_info_struct[5]), 
+  N (16, bfd_mach_msp31, "msp:31", FALSE, & arch_info_struct[8]), 
 
   /* msp430x32x.  */
-  N (16, bfd_mach_msp32, "msp:32", FALSE, & arch_info_struct[6]), 
+  N (16, bfd_mach_msp32, "msp:32", FALSE, & arch_info_struct[9]), 
 
   /* msp430x33x.  */
-  N (16, bfd_mach_msp33, "msp:33", FALSE, & arch_info_struct[7]),
+  N (16, bfd_mach_msp33, "msp:33", FALSE, & arch_info_struct[10]),
   
   /* msp430x41x.  */
-  N (16, bfd_mach_msp41, "msp:41", FALSE, & arch_info_struct[8]),
+  N (16, bfd_mach_msp41, "msp:41", FALSE, & arch_info_struct[11]),
+
+  /* msp430x42x.  */
+  N (16, bfd_mach_msp42, "msp:42", FALSE, & arch_info_struct[12]),
 
   /* msp430x43x.  */
-  N (16, bfd_mach_msp43, "msp:43", FALSE, & arch_info_struct[9]),
+  N (16, bfd_mach_msp43, "msp:43", FALSE, & arch_info_struct[13]),
 
   /* msp430x44x.  */
-  N (16, bfd_mach_msp43, "msp:44", FALSE, & arch_info_struct[10]),
-  
-  /* msp430x15x.  */
-  N (16, bfd_mach_msp15, "msp:15", FALSE, & arch_info_struct[11]),
-  
-  /* msp430x16x.  */
-  N (16, bfd_mach_msp16, "msp:16", FALSE, & arch_info_struct[12]),
-
-  /* msp430x11x1.  */
-  N (16, bfd_mach_msp110, "msp:110", FALSE, NULL)
-
+  N (16, bfd_mach_msp43, "msp:44", FALSE, NULL)
 };
 
 const bfd_arch_info_type bfd_msp430_arch =
   N (16, bfd_mach_msp14, "msp:14", TRUE, & arch_info_struct[0]);
 
