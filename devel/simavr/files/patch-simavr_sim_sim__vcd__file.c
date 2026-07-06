--- simavr/sim/sim_vcd_file.c.orig	2026-06-26 12:23:48 UTC
+++ simavr/sim/sim_vcd_file.c
@@ -34,6 +34,7 @@ DEFINE_FIFO(avr_vcd_log_t, avr_vcd_fifo);
 
 DEFINE_FIFO(avr_vcd_log_t, avr_vcd_fifo);
 
+#undef strdupa
 #define strdupa(__s) strcpy(alloca(strlen(__s)+1), __s)
 
 static void
