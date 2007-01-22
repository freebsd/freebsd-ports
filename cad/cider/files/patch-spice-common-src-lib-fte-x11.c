--- spice/common/src/lib/fte/x11.c.orig	Sun Jan 30 03:48:34 1994
+++ spice/common/src/lib/fte/x11.c	Fri Dec 22 20:24:00 2006
@@ -61,6 +61,10 @@
 
 #define DEVDEP(g) (*((X11devdep *) (g)->devdep))
 
+static int initlinestyles();
+static int initcolors();
+static int X_ScreentoData();
+
 static void linear_arc( );
 static Display *display;
 static GC xorgc;
