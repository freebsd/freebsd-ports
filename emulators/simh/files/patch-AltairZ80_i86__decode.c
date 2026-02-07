--- AltairZ80/i86_decode.c.orig	2020-09-01 09:55:27 UTC
+++ AltairZ80/i86_decode.c
@@ -46,6 +46,7 @@ extern uint32 PCX;      /* external view of PC        
 extern uint32 sim_brk_summ;
 extern UNIT cpu_unit;
 
+volatile int intr;
 void i86_intr_raise(PC_ENV *m,uint8 intrnum);
 void cpu8086reset(void);
 t_stat sim_instr_8086(void);
