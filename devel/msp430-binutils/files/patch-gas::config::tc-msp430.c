--- gas/config/tc-msp430.c.orig	Fri Aug  1 16:52:38 2003
+++ gas/config/tc-msp430.c	Fri Aug  1 17:00:31 2003
@@ -186,6 +186,8 @@
 	     "                  msp430x1101 msp430x1111\n"
 	     "                  msp430x1121 msp430x1122 msp430x1132\n"
 	     "                  msp430x122  msp430x123\n"
+	     "                  msp430x1222 msp430x1232\n"
+	     "                  msp430x133  msp430x135\n"
 	     "                  msp430x1331 msp430x1351\n"
 	     "                  msp430x147  msp430x148  msp430x149\n"
 	     "                  msp430x155  msp430x156  msp430x157\n"
@@ -979,11 +981,7 @@
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
@@ -1000,11 +998,7 @@
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
