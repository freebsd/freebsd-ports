--- telak.c.orig	Wed Sep 14 01:08:51 2005
+++ telak.c	Wed Sep 14 01:08:52 2005
@@ -91,7 +91,6 @@
       Atom SWM_VROOT = XInternAtom(display, "__SWM_VROOT", False);
       Atom NAUTILUS_DESKTOP_WINDOW_ID =
 		XInternAtom(display, "NAUTILUS_DESKTOP_WINDOW_ID", False);
-      win = DefaultRootWindow(display);
 
       Window unused, *windows = 0;
       unsigned int count;
@@ -101,6 +100,7 @@
       unsigned long nitems, bytes_after_return;
       unsigned char *virtual_root_window;
 
+      win = DefaultRootWindow(display);
       if(XGetWindowProperty(display, win, NAUTILUS_DESKTOP_WINDOW_ID,
 							0, 1, False, XA_WINDOW, &type, &format,
 							&nitems, &bytes_after_return,
