--- spice3f5/common/src/lib/fte/x11.c.orig	1994-01-29 18:48:34 UTC
+++ spice3f5/common/src/lib/fte/x11.c
@@ -61,6 +61,10 @@ typedef struct x11info {
 
 #define DEVDEP(g) (*((X11devdep *) (g)->devdep))
 
+static int initlinestyles();
+static int initcolors();
+static int X_ScreentoData();
+
 static void linear_arc( );
 static Display *display;
 static GC xorgc;
