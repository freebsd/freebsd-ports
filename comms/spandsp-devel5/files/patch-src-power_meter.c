--- src/power_meter.c.orig	Thu Jun 30 22:40:33 2005
+++ src/power_meter.c	Thu Jun 30 22:41:05 2005
@@ -72,6 +72,10 @@
 }
 /*- End of function --------------------------------------------------------*/
 
+#ifndef INFINITY
+#define INFINITY (float)HUGE_VAL
+#endif
+
 float power_meter_dbm0(power_meter_t *meter)
 {
     float val;
