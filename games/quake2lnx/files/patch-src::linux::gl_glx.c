--- src/linux/gl_glx.c.orig	Thu Oct 10 01:29:47 2002
+++ src/linux/gl_glx.c	Mon Jun 16 23:19:21 2003
@@ -475,6 +475,10 @@
 	in_state->Key_Event_fp (K_MWHEELUP, 1);
       else if (event.xbutton.button == 5)
 	in_state->Key_Event_fp (K_MWHEELDOWN, 1);
+      else if (event.xbutton.button == 6)
+	in_state->Key_Event_fp (K_MOUSE4, 1);
+      else if (event.xbutton.button == 7)
+	in_state->Key_Event_fp (K_MOUSE5, 1);
       if (b>=0 && in_state && in_state->Key_Event_fp)
 	in_state->Key_Event_fp (K_MOUSE1 + b, true);
       if (b>=0)
@@ -493,6 +497,10 @@
 	in_state->Key_Event_fp (K_MWHEELUP, 0);
       else if (event.xbutton.button == 5)
 	in_state->Key_Event_fp (K_MWHEELDOWN, 0);
+      else if (event.xbutton.button == 6)
+	in_state->Key_Event_fp (K_MOUSE4, 0);
+      else if (event.xbutton.button == 7)
+	in_state->Key_Event_fp (K_MOUSE5, 0);
       if (b>=0 && in_state && in_state->Key_Event_fp)
 	in_state->Key_Event_fp (K_MOUSE1 + b, false);
       if (b>=0)
@@ -1015,7 +1023,7 @@
 qboolean OpenJoystick(cvar_t *joy_dev) {
   int i, err;
   glob_t pglob;
-  struct js_event e;
+  struct joystick j;
 
   err = glob(joy_dev->string, 0, NULL, &pglob);
 
@@ -1030,7 +1038,7 @@
     default:
       ri.Con_Printf(PRINT_ALL, "Error #%d while looking for joysticks\n",err);
     }
-    return false;
+    goto out;
   }  
   
   for (i=0;i<pglob.gl_pathc;i++) {
@@ -1039,38 +1047,36 @@
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
 
