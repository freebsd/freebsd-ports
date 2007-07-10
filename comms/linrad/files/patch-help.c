--- help.c.orig	Wed May  9 15:23:18 2007
+++ help.c	Fri Jun 29 17:59:12 2007
@@ -370,7 +370,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="/usr/X11R6/share/linrad/errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -385,7 +385,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="/usr/X11R6/share/linrad/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
