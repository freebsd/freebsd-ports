--- help.c.orig	Tue Sep  4 18:14:33 2007
+++ help.c	Thu Sep 27 21:08:19 2007
@@ -381,7 +381,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="/usr/X11R6/share/linrad/errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -396,7 +396,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="/usr/X11R6/share/linrad/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
