--- xgraph.C.orig	Mon Aug  7 23:26:57 1995
+++ xgraph.C	Tue Nov 19 06:05:22 2002
@@ -603,7 +603,7 @@
 XSizeHints				hints;
 XEvent	event;
 static	int	offx=10;
-const	frame = 7;
+const	int frame = 7;
 
 	hints.flags = PPosition | PSize | PAspect | PMinSize | PMaxSize;
 	hints.x = DisplayWidth(dpy,scr) -offx-width-frame;
@@ -918,7 +918,7 @@
 	XFillPolygon( dpy,win,gc_current,p,n,0,0);
 
 	if (p!=buffer)									delete p;
-	va_end(arg_ptr);
+	va_end(argptr);
 }
 
 void FillPoly( int n, Vec2 v[] ) {
