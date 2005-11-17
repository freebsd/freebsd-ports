--- src/linux/rw_x11.c.orig	Wed Oct  9 03:54:25 2002
+++ src/linux/rw_x11.c	Mon Jun 16 23:19:40 2003
@@ -446,7 +446,7 @@
 qboolean OpenJoystick(cvar_t *joy_dev) {
   int i, err;
   glob_t pglob;
-  struct js_event e;
+  struct joystick j;
 
   err = glob(joy_dev->string, 0, NULL, &pglob);
 
@@ -461,7 +461,7 @@
     default:
       ri.Con_Printf(PRINT_ALL, "Error #%d while looking for joysticks\n",err);
     }
-    return false;
+    goto out;
   }  
   
   for (i=0;i<pglob.gl_pathc;i++) {
@@ -470,16 +470,14 @@
     if (joy_fd == -1) {
       ri.Con_Printf(PRINT_ALL, "Error opening joystick dev %s\n", 
 		    pglob.gl_pathv[i]);
-      return false;
+      goto out;
     }
-    else {
-      while (read(joy_fd, &e, sizeof(struct js_event))!=-1 &&
-	     (e.type & JS_EVENT_INIT))
-	ri.Con_Printf(PRINT_ALL, "Read init event\n");
+    else if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
       ri.Con_Printf(PRINT_ALL, "Using joystick dev %s\n", pglob.gl_pathv[i]);
       return true;
     }
   }
+out:
   globfree(&pglob);
   return false;
 }
@@ -1014,6 +1012,10 @@
 	in_state->Key_Event_fp (K_MWHEELUP, 1);
       else if (event.xbutton.button == 5)
 	in_state->Key_Event_fp (K_MWHEELDOWN, 1);
+      else if (event.xbutton.button == 6)
+	in_state->Key_Event_fp (K_MOUSE4, 1);
+      else if (event.xbutton.button == 7)
+	in_state->Key_Event_fp (K_MOUSE5, 1);
       if (b>=0)
 	mouse_buttonstate |= 1<<b;
       break;
@@ -1030,6 +1032,10 @@
 	in_state->Key_Event_fp (K_MWHEELUP, 0);
       else if (event.xbutton.button == 5)
 	in_state->Key_Event_fp (K_MWHEELDOWN, 0);
+      else if (event.xbutton.button == 6)
+	in_state->Key_Event_fp (K_MOUSE4, 0);
+      else if (event.xbutton.button == 7)
+	in_state->Key_Event_fp (K_MOUSE5, 0);
       if (b>=0)
 	mouse_buttonstate &= ~(1<<b);
       break;
@@ -1969,23 +1975,23 @@
 
 #ifdef Joystick
 void PlatformJoyCommands(int *axis_vals, int *axis_map) {
-  struct js_event e;
-  int key_index;
+  struct joystick j;
   in_state_t *in_state = getState();
-  
-  while (read(joy_fd, &e, sizeof(struct js_event))!=-1) {
-    if (JS_EVENT_BUTTON & e.type) {
-      key_index = (e.number < 4) ? K_JOY1 : K_AUX1;
-      if (e.value) {
-	in_state->Key_Event_fp (key_index + e.number, true);
-      }
-      else {
-	in_state->Key_Event_fp (key_index + e.number, false);
-      }
-    }
-    else if (JS_EVENT_AXIS & e.type) {
-      axis_vals[axis_map[e.number]] = e.value;
-    }
+
+  /*
+   * FreeBSD does not fully support multi-buttoned joysticks.
+   */
+  if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
+    if (j.b1)
+      in_state->Key_Event_fp (K_JOY1, true);
+    else
+      in_state->Key_Event_fp (K_JOY1, false);
+    if (j.b2)
+      in_state->Key_Event_fp (K_JOY2, true);
+    else
+      in_state->Key_Event_fp (K_JOY2, false);
+    axis_vals[axis_map[0]] = j.x;
+    axis_vals[axis_map[1]] = j.y;
   }
 }
 #endif
