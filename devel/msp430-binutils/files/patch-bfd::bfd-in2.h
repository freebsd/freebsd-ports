--- bfd/bfd-in2.h	2003-05-04 00:06:57.000000000 +0800
+++ bfd/bfd-in2.h	2003-08-06 01:51:10.000000000 +0800
@@ -1763,23 +1763,24 @@
   bfd_arch_openrisc,  /* OpenRISC */
   bfd_arch_mmix,      /* Donald Knuth's educational processor.  */
   bfd_arch_xstormy16,
 #define bfd_mach_xstormy16     1
   bfd_arch_msp430,    /* Texas Instruments MSP430 architecture.  */
-#define bfd_mach_msp110         110
 #define bfd_mach_msp11          11
+#define bfd_mach_msp110         110
 #define bfd_mach_msp12          12
 #define bfd_mach_msp13          13
 #define bfd_mach_msp14          14
-#define bfd_mach_msp41          41
+#define bfd_mach_msp15          15
+#define bfd_mach_msp16          16  
 #define bfd_mach_msp31          31
 #define bfd_mach_msp32          32
 #define bfd_mach_msp33          33
+#define bfd_mach_msp41          41
+#define bfd_mach_msp42          42
 #define bfd_mach_msp43          43
 #define bfd_mach_msp44          44
-#define bfd_mach_msp15          15
-#define bfd_mach_msp16          16  
   bfd_arch_xtensa,    /* Tensilica's Xtensa cores.  */
 #define bfd_mach_xtensa        1
   bfd_arch_last
   };
 
