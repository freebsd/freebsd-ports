--- gl_sdl.c.orig	Thu May 19 17:56:13 2005
+++ gl_sdl.c	Thu Mar 22 00:20:55 2007
@@ -108,12 +108,12 @@
 // state struct passed in Init
 static in_state_t	*in_state;
 
-static cvar_t *sensitivity;
+cvar_t *sensitivity;
 static cvar_t *my_lookstrafe;
-static cvar_t *m_side;
-static cvar_t *m_yaw;
-static cvar_t *m_pitch;
-static cvar_t *m_forward;
+cvar_t *m_side;
+cvar_t *m_yaw;
+cvar_t *m_pitch;
+cvar_t *m_forward;
 static cvar_t *my_freelook;
 
 #ifdef HAVE_JOYSTICK
@@ -321,7 +321,7 @@
 #endif
 }
 
-static void IN_DeactivateMouse( void ) 
+void IN_DeactivateMouse( void ) 
 { 
 	if (!mouse_avail)
 		return;
