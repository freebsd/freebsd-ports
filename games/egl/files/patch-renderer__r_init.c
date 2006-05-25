--- ./renderer/r_init.c.orig	Tue May 23 20:05:59 2006
+++ ./renderer/r_init.c	Tue May 23 20:06:00 2006
@@ -1395,6 +1395,7 @@
 	Com_Printf (0, "----------------------------------------\n");
 
 	// Sub-system init
+	Swap_Init();
 	R_ImageInit ();
 	R_ProgramInit ();
 	R_ShaderInit ();
