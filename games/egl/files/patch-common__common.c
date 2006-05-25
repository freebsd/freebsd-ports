--- ./common/common.c.orig	Tue May 23 20:05:59 2006
+++ ./common/common.c	Tue May 23 20:06:00 2006
@@ -645,6 +645,7 @@
 	Com_InitArgv (argc, argv);
 
 	Cmd_Init ();
+	Swap_Init ();
 	Cbuf_Init ();
 	Alias_Init ();
 	Cvar_Init ();
