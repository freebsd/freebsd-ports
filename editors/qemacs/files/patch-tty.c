--- tty.c.orig	Tue Apr 22 07:01:42 2003
+++ tty.c	Thu Jan 18 13:56:41 2007
@@ -70,7 +70,7 @@
     return 1;
 }
 
-extern QEDisplay tty_dpy;
+static QEDisplay tty_dpy;
 
 static int term_init(QEditScreen *s, int w, int h)
 {
