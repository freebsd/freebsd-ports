--- src/gl_fxmesa.c.orig	Sat Jul 20 01:30:46 2002
+++ src/gl_fxmesa.c	Wed Feb 22 20:24:51 2006
@@ -72,8 +72,6 @@
 extern cvar_t *vid_fullscreen;
 extern cvar_t *vid_ref;
 
-#define GLAPI extern
-#define GLAPIENTRY
 
 #define FXMESA_NONE		0               // to terminate attribList
 #define FXMESA_DOUBLEBUFFER     10
