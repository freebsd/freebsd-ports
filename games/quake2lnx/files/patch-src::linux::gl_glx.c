--- src/linux/gl_glx.c.orig	Thu Oct 10 01:29:47 2002
+++ src/linux/gl_glx.c	Mon Jun 16 23:19:21 2003
@@ -40,7 +40,6 @@
 #include <signal.h>
 #include <dlfcn.h>
 #ifdef Joystick
-#include <sys/stat.h>
 #include <fcntl.h>
 #endif
 #include "../ref_gl/gl_local.h"
@@ -58,7 +57,11 @@
 #include <X11/extensions/xf86dga.h>
 #include <X11/extensions/xf86vmode.h>
 #ifdef Joystick
-#include <linux/joystick.h>
+# if defined(__linux__)
+# include <linux/joystick.h>
+# elif defined(__FreeBSD__)
+# include <sys/joystick.h>
+# endif
 #include <glob.h>
 #endif
 #include <GL/glx.h>
@@ -87,18 +90,19 @@
 #ifdef Joystick
 static cvar_t   *in_joystick;
 static qboolean joystick_avail = false;
-static int joy_fd, jx, jy, jt;
+static int joy_fd, jx, jy, center_jx, center_jy;
 static cvar_t   *j_invert_y;
+static cvar_t   *j_sensitivity;
 #endif
 
 #ifdef Joystick
 void InitJoystick() {
   int i, err;
   glob_t pglob;
-  struct js_event e;
+  struct joystick j;
 
   joystick_avail = false;
-  err = glob("/dev/js*", 0, NULL, &pglob);
+  err = glob("/dev/joy*", 0, NULL, &pglob);
   
   if (err) {
     switch (err) {
@@ -111,7 +115,7 @@
     default:
       ri.Con_Printf(PRINT_ALL, "Error #%d while looking for joysticks\n",err);
     }
-    return;
+    goto out;
   }  
   
   for (i=0;i<pglob.gl_pathc;i++) {
@@ -121,15 +125,14 @@
       ri.Con_Printf(PRINT_ALL, "Error opening joystick dev %s\n", 
 		    pglob.gl_pathv[i]);
     }
-    else {
-      while (read(joy_fd, &e, sizeof(struct js_event))!=-1 &&
-	     (e.type & JS_EVENT_INIT))
-	ri.Con_Printf(PRINT_ALL, "Read init event\n");
-      ri.Con_Printf(PRINT_ALL, "Using joystick dev %s\n", pglob.gl_pathv[i]);
+    else if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
+	ri.Con_Printf(PRINT_ALL, "Using joystick dev %s\n", pglob.gl_pathv[i]);
       joystick_avail = true;
-      return;
+      center_jx = j.x; center_jy = j.y;
+      break;
     }
   }
+out:
   globfree(&pglob);
 }
 #endif
@@ -288,6 +291,7 @@
 #ifdef Joystick
 	in_joystick = ri.Cvar_Get ("in_joystick", "1", CVAR_ARCHIVE);
 	j_invert_y = ri.Cvar_Get ("j_invert_y", "1", CVAR_ARCHIVE);
+	j_sensitivity = ri.Cvar_Get ("j_sensitivity", "3", 0);
 #endif
 
 	// mouse variables
@@ -342,8 +346,7 @@
 {
 	int i;
 #ifdef Joystick
-	struct js_event e;
-	int key_index;
+	struct joystick j;
 #endif
 	if (mouse_avail) { 
 	  for (i=0 ; i<3 ; i++) {
@@ -356,31 +359,18 @@
 	  mouse_oldbuttonstate = mouse_buttonstate;
 	}
 #ifdef Joystick
+	/* FreeBSD does not fully support multi-buttoned joysticks */
 	if (joystick_avail) {
-	  while (read(joy_fd, &e, sizeof(struct js_event))!=-1) {
-	    if (JS_EVENT_BUTTON & e.type) {
-	      key_index = (e.number < 4) ? K_JOY1 : K_AUX1;
-	      if (e.value) {
-		in_state->Key_Event_fp (key_index + e.number, true);
-	      }
-	      else {
-		in_state->Key_Event_fp (key_index + e.number, false);
-	      }
-	      //joy_oldbuttonstate = e.number;
-	    }
-	    else if (JS_EVENT_AXIS & e.type) {
-	      switch (e.number) {
-	      case 0:
-		jx = e.value;
-		break;
-	      case 1:
-		jy = e.value;
-		break;
-	      case 3:
-		jt = e.value;
-		break;
-	      }
-	    }
+	  if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
+	    if (j.b1)
+	      in_state->Key_Event_fp (K_JOY1, true);
+	    else
+	      in_state->Key_Event_fp (K_JOY1, false);
+	    if (j.b2)
+	      in_state->Key_Event_fp (K_JOY2, true);
+	    else
+	      in_state->Key_Event_fp (K_JOY2, false);
+	    jx = j.x; jy = j.y;
 	  }
 	}
 #endif
@@ -393,7 +383,11 @@
 */
 void RW_IN_Move (usercmd_t *cmd)
 {
-  if (!mouse_avail)
+  if (!mouse_avail
+#ifdef Joystick
+      && !joystick_avail
+#endif
+      )
     return;
   
   if (m_filter->value)
@@ -429,25 +423,26 @@
   
 #ifdef Joystick
   if (joystick_avail) {
+    int djx = (jx - center_jx) * j_sensitivity->value / 10,
+    djy = (jy - center_jy) * j_sensitivity->value / 10;
     // add joy X/Y movement to cmd
     if ( (*in_state->in_strafe_state & 1) || 
 	 (lookstrafe->value && mlooking ))
-      cmd->sidemove += m_side->value * (jx/100);
+      cmd->sidemove += m_side->value * djx;
     else
-      in_state->viewangles[YAW] -= m_yaw->value * (jx/100);
+      in_state->viewangles[YAW] -= m_yaw->value * djx;
     
     if ( (mlooking || freelook->value) && 
 	 !(*in_state->in_strafe_state & 1))
       {
 	if (j_invert_y)
-	  in_state->viewangles[PITCH] -= m_pitch->value * (jy/100);
+	  in_state->viewangles[PITCH] -= m_pitch->value * djy;
 	else
-	  in_state->viewangles[PITCH] += m_pitch->value * (jy/100);
-	cmd->forwardmove -= m_forward->value * (jt/100);
+	  in_state->viewangles[PITCH] += m_pitch->value * djy;
       }
     else
       {
-	cmd->forwardmove -= m_forward->value * (jy/100);
+	cmd->forwardmove -= m_forward->value * djy;
       }
   }
 #endif
