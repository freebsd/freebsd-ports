--- src/linux/rw_in_svgalib.c.orig	Wed Oct  9 03:54:25 2002
+++ src/linux/rw_in_svgalib.c	Mon Jun 16 23:00:10 2003
@@ -20,11 +20,23 @@
 #include <termios.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/vt.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <signal.h>
 #include <sys/mman.h>
+#ifdef Joystick
+# if defined(__linux__)
+# include <linux/joystick.h>
+# elif defined(__FreeBSD__)
+# include <sys/joystick.h>
+# endif
+#include <fcntl.h>
+#include <glob.h>
+#include <unistd.h>
+#endif
 
 #include "vga.h"
 #include "vgakeyboard.h"
@@ -145,26 +157,22 @@
 	// 84 to 86 not used
 	scantokey[ 87] = K_F11;
 	scantokey[ 88] = K_F12;
-	// 89 to 95 not used
-	scantokey[ 96] = K_KP_ENTER; //keypad enter
-	scantokey[ 97] = K_CTRL; //right
-	scantokey[ 98] = K_KP_SLASH;
-	scantokey[ 99] = K_F12; // print screen, bind to screenshot by default
-	scantokey[100] = K_ALT; // right
-
-	scantokey[101] = K_PAUSE; // break
-	scantokey[102] = K_HOME;
-	scantokey[103] = K_UPARROW;
-	scantokey[104] = K_PGUP;
-	scantokey[105] = K_LEFTARROW;
-	scantokey[106] = K_RIGHTARROW;
-	scantokey[107] = K_END;
-	scantokey[108] = K_DOWNARROW;
-	scantokey[109] = K_PGDN;
-	scantokey[110] = K_INS;
-	scantokey[111] = K_DEL;
-
-	scantokey[119] = K_PAUSE;
+	scantokey[ 89] = K_KP_ENTER; //keypad enter
+	scantokey[ 90] = K_CTRL; //right
+	scantokey[ 91] = K_KP_SLASH;
+	scantokey[ 92] = K_F12; // print screen, bind to screenshot by default
+	scantokey[ 93] = K_ALT; // right
+	scantokey[ 94] = K_HOME;
+	scantokey[ 95] = K_UPARROW;
+	scantokey[ 96] = K_PGUP;
+	scantokey[ 97] = K_LEFTARROW;
+	scantokey[ 98] = K_RIGHTARROW;
+	scantokey[ 99] = K_END;
+	scantokey[100] = K_DOWNARROW;
+	scantokey[101] = K_PGDN;
+	scantokey[102] = K_INS;
+	scantokey[103] = K_DEL;
+	scantokey[104] = K_PAUSE;
 
 	if (keyboard_init())
 		Sys_Error("keyboard_init() failed");
@@ -184,7 +192,7 @@
 }
 
 /*****************************************************************************/
-/* MOUSE                                                                     */
+/* MOUSE AND JOYSTICK                                                        */
 /*****************************************************************************/
 
 // this is inside the renderer shared lib, so these are called from vid_so
@@ -207,6 +215,14 @@
 static cvar_t	*mdev;
 static cvar_t	*mrate;
 
+#ifdef Joystick
+static cvar_t	*in_joystick;
+static qboolean	joystick_avail = false;
+static int	joy_fd, jx, jy, center_jx, center_jy;
+static cvar_t	*j_invert_y;
+static cvar_t	*j_sensitivity;
+#endif
+
 static qboolean	mlooking;
 
 // state struct passed in Init
@@ -254,6 +270,49 @@
 }
 #endif
 
+#ifdef Joystick
+void
+InitJoystick()
+{
+	int i, err;
+	glob_t pglob;
+	struct joystick j;
+
+	err = glob("/dev/joy*", 0, NULL, &pglob);
+ 
+	if (err) {
+		switch (err) {
+		    case GLOB_NOSPACE:
+			ri.Con_Printf(PRINT_ALL, "Error, out of memory while looking for joysticks\n");
+			break;
+		    case GLOB_NOMATCH:
+			ri.Con_Printf(PRINT_ALL, "No joysticks found\n");
+			break;
+		    default:
+			ri.Con_Printf(PRINT_ALL, "Error #%d while looking for joysticks\n", err);
+		}
+		goto out;
+	}
+
+	for (i = 0; i < pglob.gl_pathc; i++) {
+		ri.Con_Printf(PRINT_ALL, "Trying joystick dev %s\n", pglob.gl_pathv[i]);
+		joy_fd = open(pglob.gl_pathv[i], O_RDONLY | O_NONBLOCK);
+		if (joy_fd == -1) {
+			ri.Con_Printf(PRINT_ALL, "Error opening joystick dev %s\n", 
+			pglob.gl_pathv[i]);
+		}
+		else if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
+			ri.Con_Printf(PRINT_ALL, "Using joystick dev %s\n", pglob.gl_pathv[i]);
+			joystick_avail = true;
+			center_jx = j.x; center_jy = j.y;
+			break;
+		}
+	}
+out:
+	globfree(&pglob);
+}
+#endif
+
 void RW_IN_Init(in_state_t *in_state_p)
 {
 	int mtype;
@@ -262,7 +321,12 @@
 
 	// mouse variables
 	m_filter = ri.Cvar_Get ("m_filter", "0", 0);
-    in_mouse = ri.Cvar_Get ("in_mouse", "1", CVAR_ARCHIVE);
+	in_mouse = ri.Cvar_Get ("in_mouse", "1", CVAR_ARCHIVE);
+#ifdef Joystick
+	in_joystick = ri.Cvar_Get ("in_joystick", "1", CVAR_ARCHIVE);
+	j_invert_y = ri.Cvar_Get ("j_invert_y", "1", CVAR_ARCHIVE);
+	j_sensitivity = ri.Cvar_Get ("j_sensitivity", "3", 0);
+#endif
 	freelook = ri.Cvar_Get( "freelook", "0", 0 );
 	lookstrafe = ri.Cvar_Get ("lookstrafe", "0", 0);
 	sensitivity = ri.Cvar_Get ("sensitivity", "3", 0);
@@ -293,11 +357,20 @@
 	}
 	else
 		mouse_seteventhandler(mousehandler);
+#ifdef Joystick
+	if (in_joystick)
+		InitJoystick();
+#endif
 }
 
 void RW_IN_Shutdown(void)
 {
 	mouse_close();
+#ifdef Joystick
+	if (joystick_avail)
+	    if (close(joy_fd))
+		ri.Con_Printf(PRINT_ALL, "Error, problem closing joystick\n");
+#endif
 }
 
 /*
@@ -307,7 +380,14 @@
 */
 void RW_IN_Commands (void)
 {
-	if (!UseMouse)
+#ifdef Joystick
+	struct joystick j;
+#endif
+	if (!UseMouse
+#ifdef Joystick
+	    && !joystick_avail
+#endif
+	    )
 		return;
 
 	// poll mouse values
@@ -346,6 +426,23 @@
 		in_state->Key_Event_fp (K_MWHEELDOWN, false);
 	}	
 	mwheel = 0;
+
+#ifdef Joystick
+	/* FreeBSD does not fully support multi-buttoned joysticks */
+	if (joystick_avail) {
+		if (read(joy_fd, &j, sizeof(struct joystick)) != -1) {
+			if (j.b1)
+				in_state->Key_Event_fp (K_JOY1, true);
+			else
+				in_state->Key_Event_fp (K_JOY1, false);
+			if (j.b2)
+				in_state->Key_Event_fp (K_JOY2, true);
+			else
+				in_state->Key_Event_fp (K_JOY2, false);
+			jx = j.x; jy = j.y;
+		}
+	}
+#endif
 }
 
 /*
@@ -355,7 +452,11 @@
 */
 void RW_IN_Move (usercmd_t *cmd)
 {
-	if (!UseMouse)
+	if (!UseMouse
+#ifdef Joystick
+	    && !joystick_avail
+#endif
+	    )
 		return;
 
 	// poll mouse values
@@ -374,7 +475,11 @@
 	old_mouse_x = mx;
 	old_mouse_y = my;
 
-	if (!mx && !my)
+	if (!mx && !my
+#ifdef Joystick
+	    && !joystick_avail
+#endif
+	    )
 		return;
 
 	mx = my = 0; // clear for next update
@@ -398,6 +503,28 @@
 	{
 		cmd->forwardmove -= m_forward->value * mouse_y;
 	}
+
+#ifdef Joystick
+	if (joystick_avail) {
+		int djx = (jx - center_jx) * j_sensitivity->value / 10,
+		djy = (jy - center_jy) * j_sensitivity->value / 10;
+// add joy X/Y movement to cmd
+		if ((*in_state->in_strafe_state & 1) || 
+		    (lookstrafe->value && mlooking))
+			cmd->sidemove += m_side->value * djx;
+		else
+			in_state->viewangles[YAW] -= m_yaw->value * djx;
+
+		if ((mlooking || freelook->value) && 
+		    !(*in_state->in_strafe_state & 1)) {
+			if (j_invert_y)
+				in_state->viewangles[PITCH] -= m_pitch->value * djy;
+			else
+				in_state->viewangles[PITCH] += m_pitch->value * djy;
+		}
+		else cmd->forwardmove -= m_forward->value * djy;
+	}
+#endif
 }
 
 void RW_IN_Frame (void)
