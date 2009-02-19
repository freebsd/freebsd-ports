--- common/in_x11.c.orig	2009-01-24 11:18:46.000000000 +0100
+++ common/in_x11.c	2009-01-24 11:27:30.000000000 +0100
@@ -25,15 +25,11 @@
 #include "vid.h"
 #include "sys.h"
 
-#include <X11/extensions/xf86dga.h>
-
 // FIXME - make static when possible
 qboolean mouse_available = false;	// Mouse available for use
 
 static qboolean keyboard_grab_active = false;
 qboolean mouse_grab_active = false;
-static qboolean dga_available = false;
-qboolean dga_mouse_active = false;
 
 int mouse_x, mouse_y;
 
@@ -58,41 +54,7 @@
 }
 
 
-static void
-IN_ActivateDGAMouse(void)
-{
-    if (dga_available && !dga_mouse_active) {
-	XF86DGADirectVideo(x_disp, DefaultScreen(x_disp), XF86DGADirectMouse);
-	dga_mouse_active = true;
-    }
-}
-
-static void
-IN_DeactivateDGAMouse(void)
-{
-    if (dga_available && dga_mouse_active) {
-	XF86DGADirectVideo(x_disp, DefaultScreen(x_disp), 0);
-	dga_mouse_active = false;
-	IN_CenterMouse();	// maybe set mouse_x = 0 and mouse_y = 0?
-    }
-}
-
-static void
-in_dgamouse_f(struct cvar_s *var)
-{
-    if (var->value) {
-	Con_DPrintf("Callback: in_dgamouse ON\n");
-	IN_ActivateDGAMouse();
-    } else {
-	Con_DPrintf("Callback: in_dgamouse OFF\n");
-	IN_DeactivateDGAMouse();
-    }
-}
-
 cvar_t in_mouse = { "in_mouse", "1", false };
-cvar_t in_dgamouse = { "in_dgamouse", "1", false, false, 0,
-    in_dgamouse_f
-};
 cvar_t _windowed_mouse = { "_windowed_mouse", "0", true, false, 0,
     windowed_mouse_f
 };
@@ -154,13 +116,6 @@
 	}
 	mouse_grab_active = true;
 
-	// FIXME - need those cvar callbacks to fix changed values...
-	if (dga_available) {
-	    if (in_dgamouse.value)
-		IN_ActivateDGAMouse();
-	} else {
-	    in_dgamouse.value = 0;
-	}
     } else {
 	Sys_Error("Bad grab?");
     }
@@ -174,10 +129,6 @@
 	XUndefineCursor(x_disp, x_win);
 	mouse_grab_active = false;
     }
-
-    if (dga_mouse_active) {
-	IN_DeactivateDGAMouse();
-    }
 }
 
 void
@@ -208,7 +159,6 @@
 IN_InitCvars(void)
 {
     Cvar_RegisterVariable(&in_mouse);
-    Cvar_RegisterVariable(&in_dgamouse);
     Cvar_RegisterVariable(&m_filter);
     Cvar_RegisterVariable(&_windowed_mouse);
 }
@@ -220,7 +170,6 @@
 
     keyboard_grab_active = false;
     mouse_grab_active = false;
-    dga_mouse_active = false;
 
     // FIXME - do proper detection?
     //       - Also, look at other vid_*.c files for clues
@@ -229,14 +178,6 @@
     if (x_disp == NULL)
 	Sys_Error("x_disp not initialised before input...");
 
-    if (!XF86DGAQueryVersion(x_disp, &MajorVersion, &MinorVersion)) {
-	Con_Printf("Failed to detect XF86DGA Mouse\n");
-	in_dgamouse.value = 0;
-	dga_available = false;
-    } else {
-	dga_available = true;
-    }
-
     // Need to grab the input focus at startup, just in case...
     // FIXME - must be viewable or get BadMatch
     XSetInputFocus(x_disp, x_win, RevertToParent, CurrentTime);
