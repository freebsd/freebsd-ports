--- gas/config/tc-msp430.c.orig	Tue Aug  3 12:55:44 2004
+++ gas/config/tc-msp430.c	Tue Aug  3 12:55:52 2004
@@ -119,6 +119,9 @@
   {"msp430x167", MSP430_ISA_16, bfd_mach_msp16},
   {"msp430x168", MSP430_ISA_16, bfd_mach_msp16},
   {"msp430x169", MSP430_ISA_16, bfd_mach_msp16},
+  {"msp430x1610", MSP430_ISA_16, bfd_mach_msp16},
+  {"msp430x1611", MSP430_ISA_16, bfd_mach_msp16},
+  {"msp430x1612", MSP430_ISA_16, bfd_mach_msp16},
 
   {"msp430x311", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x312", MSP430_ISA_31, bfd_mach_msp31},
@@ -132,6 +135,8 @@
 
   {"msp430x412", MSP430_ISA_41, bfd_mach_msp41},
   {"msp430x413", MSP430_ISA_41, bfd_mach_msp41},
+  {"msp430x415", MSP430_ISA_41, bfd_mach_msp41},
+  {"msp430x417", MSP430_ISA_41, bfd_mach_msp41},
 
   {"msp430xE423", MSP430_ISA_42, bfd_mach_msp42},
   {"msp430xE425", MSP430_ISA_42, bfd_mach_msp42},
