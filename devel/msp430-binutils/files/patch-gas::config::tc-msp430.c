--- gas/config/tc-msp430.c.orig	Tue Mar  4 19:34:40 2003
+++ gas/config/tc-msp430.c	Mon Aug 11 17:21:43 2003
@@ -69,72 +69,85 @@
   int isa;
   int mach;
 };
 
 #define MSP430_ISA_11   11
+#define MSP430_ISA_110	110
 #define MSP430_ISA_12   12
 #define MSP430_ISA_13   13
 #define MSP430_ISA_14   14
-#define MSP430_ISA_41   41
+#define MSP430_ISA_15   15
+#define MSP430_ISA_16   16
 #define MSP430_ISA_31   31
 #define MSP430_ISA_32   32
 #define MSP430_ISA_33   33
-#define MSP430_ISA_110	110
+#define MSP430_ISA_41   41
+#define MSP430_ISA_42   42
 #define MSP430_ISA_43   43
 #define MSP430_ISA_44   44
-#define MSP430_ISA_15   15
-#define MSP430_ISA_16   16
 
 #define CHECK_RELOC_MSP430 		((imm_op || byte_op)?BFD_RELOC_MSP430_16_BYTE:BFD_RELOC_MSP430_16)
 #define CHECK_RELOC_MSP430_PCREL	((imm_op || byte_op)?BFD_RELOC_MSP430_16_PCREL_BYTE:BFD_RELOC_MSP430_16_PCREL)
 
 static struct mcu_type_s mcu_types[] =
 {
   {"msp1",       MSP430_ISA_11, bfd_mach_msp11},
   {"msp2",       MSP430_ISA_14, bfd_mach_msp14},
   {"msp430x110", MSP430_ISA_11, bfd_mach_msp11},
   {"msp430x112", MSP430_ISA_11, bfd_mach_msp11},
-  {"msp430x122", MSP430_ISA_12, bfd_mach_msp12},
-  {"msp430x122", MSP430_ISA_12, bfd_mach_msp12},
-  {"msp430x1222",MSP430_ISA_12, bfd_mach_msp12},
+  {"msp430x1101",MSP430_ISA_110, bfd_mach_msp110},
+  {"msp430x1111",MSP430_ISA_110, bfd_mach_msp110},
+  {"msp430x1121",MSP430_ISA_110, bfd_mach_msp110},
   {"msp430x1122",MSP430_ISA_11, bfd_mach_msp110},
   {"msp430x1132",MSP430_ISA_11, bfd_mach_msp110},
+
+  {"msp430x122", MSP430_ISA_12, bfd_mach_msp12},
   {"msp430x123", MSP430_ISA_12, bfd_mach_msp12},
+  {"msp430x1222",MSP430_ISA_12, bfd_mach_msp12},
   {"msp430x1232",MSP430_ISA_12, bfd_mach_msp12},
+
   {"msp430x133", MSP430_ISA_13, bfd_mach_msp13},
   {"msp430x135", MSP430_ISA_13, bfd_mach_msp13},
+  {"msp430x1331",MSP430_ISA_13, bfd_mach_msp13},
+  {"msp430x1351",MSP430_ISA_13, bfd_mach_msp13},
   {"msp430x147", MSP430_ISA_14, bfd_mach_msp14},
   {"msp430x148", MSP430_ISA_14, bfd_mach_msp14},
   {"msp430x149", MSP430_ISA_14, bfd_mach_msp14},
-  {"msp430x412", MSP430_ISA_41, bfd_mach_msp41},
-  {"msp430x413", MSP430_ISA_41, bfd_mach_msp41},
+
+  {"msp430x155", MSP430_ISA_15, bfd_mach_msp15},
+  {"msp430x156", MSP430_ISA_15, bfd_mach_msp15},
+  {"msp430x157", MSP430_ISA_15, bfd_mach_msp15},
+  {"msp430x167", MSP430_ISA_16, bfd_mach_msp16},
+  {"msp430x168", MSP430_ISA_16, bfd_mach_msp16},
+  {"msp430x169", MSP430_ISA_16, bfd_mach_msp16},
+
   {"msp430x311", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x312", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x313", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x314", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x315", MSP430_ISA_31, bfd_mach_msp31},
   {"msp430x323", MSP430_ISA_32, bfd_mach_msp32},
   {"msp430x325", MSP430_ISA_32, bfd_mach_msp32},
   {"msp430x336", MSP430_ISA_33, bfd_mach_msp33},
   {"msp430x337", MSP430_ISA_33, bfd_mach_msp33},
-  {"msp430x1101",MSP430_ISA_110, bfd_mach_msp110},
-  {"msp430x1111",MSP430_ISA_110, bfd_mach_msp110},
-  {"msp430x1121",MSP430_ISA_110, bfd_mach_msp110},
-  {"msp430x1331",MSP430_ISA_13, bfd_mach_msp13},
-  {"msp430x1351",MSP430_ISA_13, bfd_mach_msp13},
+
+  {"msp430x412", MSP430_ISA_41, bfd_mach_msp41},
+  {"msp430x413", MSP430_ISA_41, bfd_mach_msp41},
+
+  {"msp430xE423", MSP430_ISA_42, bfd_mach_msp42},
+  {"msp430xE425", MSP430_ISA_42, bfd_mach_msp42},
+  {"msp430xE427", MSP430_ISA_42, bfd_mach_msp42},
+  {"msp430xW423", MSP430_ISA_42, bfd_mach_msp42},
+  {"msp430xW425", MSP430_ISA_42, bfd_mach_msp42},
+  {"msp430xW427", MSP430_ISA_42, bfd_mach_msp42},
+
   {"msp430x435", MSP430_ISA_43, bfd_mach_msp43},
   {"msp430x436", MSP430_ISA_43, bfd_mach_msp43},
   {"msp430x437", MSP430_ISA_43, bfd_mach_msp43},
   {"msp430x447", MSP430_ISA_44, bfd_mach_msp44},
   {"msp430x448", MSP430_ISA_44, bfd_mach_msp44},
   {"msp430x449", MSP430_ISA_44, bfd_mach_msp44},
-  {"msp430x167", MSP430_ISA_16, bfd_mach_msp16},
-  {"msp430x168", MSP430_ISA_16, bfd_mach_msp16},
-  {"msp430x169", MSP430_ISA_16, bfd_mach_msp16},
-  {"msp430x155", MSP430_ISA_15, bfd_mach_msp15},
-  {"msp430x156", MSP430_ISA_15, bfd_mach_msp15},
-  {"msp430x157", MSP430_ISA_15, bfd_mach_msp15},
 
   {NULL, 0, 0}
 };
 
 
@@ -184,18 +197,22 @@
 	     "  -mmcu=[msp430-name] select microcontroller type\n"
 	     "                  msp430x110  msp430x112\n"
 	     "                  msp430x1101 msp430x1111\n"
 	     "                  msp430x1121 msp430x1122 msp430x1132\n"
 	     "                  msp430x122  msp430x123\n"
+	     "                  msp430x1222 msp430x1232\n"
+	     "                  msp430x133  msp430x135\n"
 	     "                  msp430x1331 msp430x1351\n"
 	     "                  msp430x147  msp430x148  msp430x149\n"
 	     "                  msp430x155  msp430x156  msp430x157\n"
 	     "                  msp430x167  msp430x168  msp430x169\n"
 	     "                  msp430x311  msp430x312  msp430x313  msp430x314  msp430x315\n"
 	     "                  msp430x323  msp430x325\n"
 	     "                  msp430x336  msp430x337\n"
 	     "                  msp430x412  msp430x413\n"
+	     "                  msp430xE423 msp430xE425 msp430E427\n"
+	     "                  msp430xW423 msp430xW425 msp430W427\n"
 	     "                  msp430x435  msp430x436  msp430x437\n"
 	     "                  msp430x447  msp430x448  msp430x449\n"));
 
   show_mcu_list (stream);
 }
@@ -977,15 +994,11 @@
 	      op->mode = OP_REG;
 	    }
 	  else if (x == 4)
 	    {
 #ifdef PUSH_1X_WORKAROUND
-	      if (bin == 0x1200
-		  && (msp430_mcu->isa == MSP430_ISA_11
-		      || msp430_mcu->isa == MSP430_ISA_12
-		      || msp430_mcu->isa == MSP430_ISA_13
-		      || msp430_mcu->isa == MSP430_ISA_14))
+	      if (bin == 0x1200)
 		{
 		  /* Remove warning as confusing.
 		     as_warn(_("Hardware push bug workaround")); */
 		}
 	      else
@@ -998,15 +1011,11 @@
 		}
 	    }
 	  else if (x == 8)
 	    {
 #ifdef PUSH_1X_WORKAROUND
-	      if (bin == 0x1200
-		  && (msp430_mcu->isa == MSP430_ISA_11
-		      || msp430_mcu->isa == MSP430_ISA_12
-		      || msp430_mcu->isa == MSP430_ISA_13
-		      || msp430_mcu->isa == MSP430_ISA_14))
+	      if (bin == 0x1200)
 		{
 		  /* Remove warning as confusing.
 		     as_warn(_("Hardware push bug workaround")); */
 		}
 	      else
