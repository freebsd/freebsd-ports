--- src/interrupt.c.orig	2005-12-11 11:18:27 UTC
+++ src/interrupt.c
@@ -28,6 +28,9 @@
 
 #define DELAY_CYCLE 24
 
+GBTIMER *gbtimer;
+GBLCDC *gblcdc;
+
 static const Uint16 lcd_cycle_tab[2][5]={{204,456,80,172,80},              /* GB */
 					 {204*2,456*2,80*2,172*2,80*2}}; /* CGB */
 
