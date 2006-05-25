--- ./linux/x11_main.c.orig	Tue May 23 20:05:59 2006
+++ ./linux/x11_main.c	Tue May 23 20:06:00 2006
@@ -147,7 +147,7 @@
 	}
 }
 
-static void X11_SetKMGrab (qBool kg, qBool mg)
+void X11_SetKMGrab (qBool kg, qBool mg)
 {
 	keybd_grabbed = kg;
 	mouse_grabbed = mg;
