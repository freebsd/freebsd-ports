--- xtruco.c.orig	2011-09-28 10:45:56.000000000 +0800
+++ xtruco.c	2011-09-28 10:51:28.000000000 +0800
@@ -67,6 +67,7 @@ int			pc, you, Who_Play, You_Play, first
 int			alert, Sum_Val, ValGame, danger, Begining;
 int			Play, Beginer, Who_Say_Truco,score1, score2;
 int			SHOW=1;
+void Refresh(Display *, Window, GC, Pixmap, int, int, int, int);
 
 main( argc, argv )
 int argc;
@@ -603,6 +604,7 @@ int         *width, *height;
     return( True );
 }
 
+void
 Refresh( display, window, gc, pixmap, x, y, width, height )
 Display   *display;
 Window    window;
@@ -632,6 +634,7 @@ int       x, y, width, height;
     }
     XCopyArea( display, pixmap, window, gc, x, y, width,
 			height, x, y );
+	return;
 }
 
 MakeButtons( display, window, gc, fore, back, font_id, h, v )
