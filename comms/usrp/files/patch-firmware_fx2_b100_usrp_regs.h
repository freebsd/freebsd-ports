--- firmware/fx2/b100/usrp_regs.h.orig	2012-10-10 16:32:04.000000000 -0500
+++ firmware/fx2/b100/usrp_regs.h	2012-10-10 16:33:34.000000000 -0500
@@ -59,11 +59,11 @@
 #define PORT_A_ADDR 0x80
 #define PORT_C_ADDR 0xA0
 
-sbit at PORT_A_ADDR+0 bitALTERA_DCLK;	// 0x80 is the bit address of PORT A
-sbit at PORT_A_ADDR+1 bitALTERA_NCONFIG;
-sbit at PORT_A_ADDR+3 bitALTERA_DATA0;
+__sbit __at PORT_A_ADDR+0 bitALTERA_DCLK;	// 0x80 is the bit address of PORT A
+__sbit __at PORT_A_ADDR+1 bitALTERA_NCONFIG;
+__sbit __at PORT_A_ADDR+3 bitALTERA_DATA0;
 
-sbit at PORT_C_ADDR+7 bitALTERA_CONF_DONE;
+__sbit __at PORT_C_ADDR+7 bitALTERA_CONF_DONE;
 
 
 /* Port B: GPIF	FD[7:0]			*/
