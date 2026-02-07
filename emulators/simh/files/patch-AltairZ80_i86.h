--- AltairZ80/i86.h.orig	2020-09-01 09:55:27 UTC
+++ AltairZ80/i86.h
@@ -215,7 +215,6 @@ struct  pc_env
 };
 
 /* GLOBAL */
-volatile int intr;
 
 void halt_sys (PC_ENV *sys);
 void fetch_decode_modrm (PC_ENV *m, uint16 *mod, uint16 *regh, uint16 *regl);
