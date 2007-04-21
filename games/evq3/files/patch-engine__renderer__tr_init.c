--- ./engine/renderer/tr_init.c.orig	Tue Apr  3 15:02:50 2007
+++ ./engine/renderer/tr_init.c	Mon Apr 16 23:58:43 2007
@@ -1108,7 +1108,7 @@
 	r_simpleMipMaps = ri.Cvar_Get("r_simpleMipMaps", "1", CVAR_ARCHIVE | CVAR_LATCH);
 	r_uiFullScreen = ri.Cvar_Get("r_uifullscreen", "0", 0);
 	r_subdivisions = ri.Cvar_Get("r_subdivisions", "4", CVAR_ARCHIVE | CVAR_LATCH);
-#if (defined(MACOS_X) || defined(__linux__)) && defined(SMP)
+#if (defined(MACOS_X) || defined(__unix__)) && defined(SMP)
 	// Default to using SMP on Mac OS X or Linux if we have multiple processors
 	r_smp = ri.Cvar_Get("r_smp", Sys_ProcessorCount() > 1 ? "1" : "0", CVAR_ARCHIVE | CVAR_LATCH);
 #else
