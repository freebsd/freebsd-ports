--- ./gl_rmain.c.orig	Thu May 19 17:56:13 2005
+++ ./gl_rmain.c	Sun Feb 26 11:23:56 2006
@@ -1450,7 +1450,7 @@
 		ri.Cvar_Set( "scr_drawall", "0" );
 	}
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	ri.Cvar_SetValue( "gl_finish", 0 );
 #endif
 
