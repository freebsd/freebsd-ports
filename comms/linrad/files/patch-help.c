--- help.c.orig	2009-03-09 17:29:26.000000000 -0400
+++ help.c	2009-03-22 16:09:52.000000000 -0400
@@ -430,7 +430,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%DATADIR%%/errors.lir";
 line=3;
 if(screen_mode)
   {
@@ -445,7 +445,7 @@
 {
 int line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%DATADIR%%/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
