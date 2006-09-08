--- help.c.orig	Fri Jul 28 13:12:59 2006
+++ help.c	Sat Jul 29 00:50:34 2006
@@ -337,7 +337,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%DATADIR%%errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -352,7 +352,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%DATADIR%%help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
