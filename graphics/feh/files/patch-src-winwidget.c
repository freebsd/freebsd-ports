--- src/winwidget.c.orig	2005-07-14 13:59:03.000000000 +0200
+++ src/winwidget.c	2009-03-11 21:46:33.000000000 +0100
@@ -158,6 +158,7 @@
                         int h)
 {
   XSetWindowAttributes attr;
+  XEvent ev;
   XClassHint *xch;
   MWMHints mwmhints;
   Atom prop = None;
@@ -256,6 +257,22 @@
     XChangeProperty(disp, ret->win, prop, prop, 32, PropModeReplace,
                     (unsigned char *) &mwmhints, PROP_MWM_HINTS_ELEMENTS);
   }
+  if (ret->full_screen) {
+    Atom prop_fs = XInternAtom(disp, "_NET_WM_STATE_FULLSCREEN",  False);
+	Atom prop_state = XInternAtom(disp, "_NET_WM_STATE", False);
+
+	memset(&ev, 0, sizeof(ev));
+	ev.xclient.type = ClientMessage;
+	ev.xclient.message_type = prop_state;
+	ev.xclient.display = disp;
+	ev.xclient.window = ret->win;
+	ev.xclient.format = 32;
+	ev.xclient.data.l[0] = (ret->full_screen ? 1 : 0);
+	ev.xclient.data.l[1] = prop_fs;
+
+    XChangeProperty(disp, ret->win, prop_state, XA_ATOM, 32,
+					PropModeReplace, &prop_fs, 1);
+  }
 
   XSetWMProtocols(disp, ret->win, &wmDeleteWindow, 1);
   winwidget_update_title(ret);
