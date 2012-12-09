--- firmware/fx2/usrp1/usrp_regs.h.orig	2012-10-07 20:07:53.000000000 -0500
+++ firmware/fx2/usrp1/usrp_regs.h	2012-10-07 20:08:24.000000000 -0500
@@ -47,9 +47,9 @@
 #define	bmPA_TX_UNDERRUN	bmBIT7		// misc pin to FPGA (underflow)
 
 
-sbit at 0x80+0 bitS_CLK;		// 0x80 is the bit address of PORT A
-sbit at 0x80+1 bitS_OUT;		// out from FX2 point of view
-sbit at 0x80+2 bitS_IN;			// in from FX2 point of view
+__sbit __at 0x80+0 bitS_CLK;		// 0x80 is the bit address of PORT A
+__sbit __at 0x80+1 bitS_OUT;		// out from FX2 point of view
+__sbit __at 0x80+2 bitS_IN;			// in from FX2 point of view
 
 
 /* all outputs except S_DATA_FROM_PERIPH, FX2_2, FX2_3 */
@@ -85,8 +85,8 @@
 #define	bmPC_LED0		bmBIT6		// active low
 #define	bmPC_LED1		bmBIT7		// active low
 
-sbit at 0xA0+1 bitALTERA_DATA0;		// 0xA0 is the bit address of PORT C
-sbit at 0xA0+3 bitALTERA_DCLK;
+__sbit __at 0xA0+1 bitALTERA_DATA0;		// 0xA0 is the bit address of PORT C
+__sbit __at 0xA0+3 bitALTERA_DCLK;
 
 
 #define	bmALTERA_BITS		(bmALTERA_DATA0			\
