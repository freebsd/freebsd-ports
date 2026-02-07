--- title.c.orig	1998-07-04 01:35:00 UTC
+++ title.c
@@ -20,12 +20,12 @@ Pixmap p_title;
 XImage *title_image;
 char *tdata;
 
-XEvent ev;
+extern XEvent ev;
 
 Pixel *ti_col;
 unsigned int ti_num;
 
-XpmAttributes xpatt;
+extern XpmAttributes xpatt;
 
 int torg_x, torg_y;
 int t_oy;
@@ -55,7 +55,7 @@ static char *keys[] = {
 static int key_msg = 10;
 
 #ifndef SIG_SET
-struct sigaction act;
+extern struct sigaction act;
 #endif
 
 void title()
