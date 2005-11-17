--- src/linux/rw_linux.c.orig	Sun Jan  2 09:46:35 2005
+++ src/linux/rw_linux.c	Wed Mar  9 17:40:28 2005
@@ -31,6 +31,10 @@
 static int mouse_buttonstate;
 static int mouse_oldbuttonstate;
 
+#ifdef OPENGL
+static cvar_t *use_stencil;
+#endif
+
 in_state_t *getState() {
   return in_state;
 }
