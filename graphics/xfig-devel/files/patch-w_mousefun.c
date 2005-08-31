--- w_mousefun.c.orig	Wed Mar 27 01:22:48 2002
+++ w_mousefun.c	Wed Aug 31 09:49:42 2005
@@ -54,9 +54,11 @@
 static Pixmap	mousefun_pm;
 static Pixmap	keybd_pm;
 
+#ifndef XAW3D
 /* popup message over button when mouse enters it */
 static void     mouse_balloon_trigger();
 static void     mouse_unballoon();
+#endif
 
 void
 init_mousefun(tool)
@@ -81,11 +83,15 @@
 
     mousefun = XtCreateManagedWidget("mouse_panel", labelWidgetClass,
 				     tool, Args, ArgCount);
+#ifdef XAW3D
+    update_mousepanel();
+#else
     /* popup when mouse passes over button */
     XtAddEventHandler(mousefun, EnterWindowMask, False,
 		      mouse_balloon_trigger, (XtPointer) mousefun);
     XtAddEventHandler(mousefun, LeaveWindowMask, False,
 		      mouse_unballoon, (XtPointer) mousefun);
+#endif
 }
 
 /* widgets are realized and windows exist at this point */
@@ -105,6 +111,17 @@
     set_mousefun("", "", "", "", "", "");
 }
 
+#ifdef XAW3D
+update_mousepanel()
+{
+    if (mousefun)
+	if (appres.showballoons)
+	    XawTipEnable(mousefun,
+			 "Shows which mouse buttons\nare active in each mode");
+	else
+	    XawTipDisable(mousefun);
+}
+#else
 /* come here when the mouse passes over a button in the mouse indicator panel */
 
 static	Widget mouse_balloon_popup = (Widget) 0;
@@ -184,6 +201,7 @@
 	mouse_balloon_popup = (Widget) 0;
     }
 }
+#endif
 
 static void
 reset_mousefun()
