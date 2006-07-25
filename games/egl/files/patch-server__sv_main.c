--- server/sv_main.c.orig	Mon Jul 24 15:06:36 2006
+++ server/sv_main.c	Mon Jul 24 15:09:02 2006
@@ -145,6 +145,7 @@
 */
 void SV_UpdateTitle (void)
 {
+#if 0
 	hostname->modified = qFalse;
 
 	if (Com_ServerState() == SS_GAME) {
@@ -153,6 +154,7 @@
 	}
 
 	Sys_SetConsoleTitle (NULL);
+#endif
 }
 
 /*
