--- help.c.orig	Wed Feb 14 04:37:46 2007
+++ help.c	Thu Feb 22 18:44:17 2007
@@ -352,7 +352,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="/usr/X11R6/share/linrad/errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -367,7 +367,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="/usr/X11R6/share/linrad/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
