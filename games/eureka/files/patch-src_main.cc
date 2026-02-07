--- src/main.cc.orig	2020-02-01 07:51:21 UTC
+++ src/main.cc
@@ -49,6 +49,7 @@
 
 #ifndef WIN32
 #include <time.h>
+#include <X11/xpm.h>	// for the window icon
 #endif
 
 // IOANCH: be able to call OSX specific routines (needed for ~/Library)
@@ -646,6 +647,16 @@ static void Main_OpenWindow()
 
 	main_win->label("Eureka v" EUREKA_VERSION);
 
+#include "../misc/eureka.xpm"
+
+	// needed if display has not been previously opened
+	fl_open_display();
+
+	Pixmap p, mask;
+	XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
+	    logo_E4_32x32_xpm, &p, &mask, NULL);
+	main_win->icon((char *)p);
+
 	// show window (pass some dummy arguments)
 	{
 		int   argc = 1;
@@ -660,6 +671,15 @@ static void Main_OpenWindow()
 #endif
 		app_has_focus = true;
 	}
+
+	// read in the current window hints, then modify them to
+	// support icon transparency (make sure that transparency
+	// mask is enabled in the XPM icon)
+	XWMHints* hints = XGetWMHints(fl_display, fl_xid(main_win));
+	hints->flags |= IconMaskHint;
+	hints->icon_mask = mask;
+	XSetWMHints(fl_display, fl_xid(main_win), hints);
+	XFree(hints);
 
 	// kill the stupid bright background of the "plastic" scheme
 	if (gui_scheme == 2)
