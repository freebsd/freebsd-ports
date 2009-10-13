--- help.c.orig	2009-08-26 18:48:32.000000000 -0400
+++ help.c	2009-09-01 19:16:42.000000000 -0400
@@ -434,7 +434,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%DATADIR%%/errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -449,7 +449,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%DATADIR%%/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
