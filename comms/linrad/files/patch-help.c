--- help.c.orig	Sat May 27 07:48:22 2006
+++ help.c	Tue Jun 20 20:37:14 2006
@@ -344,7 +344,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%DATADIR%%errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -359,7 +359,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%DATADIR%%help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
