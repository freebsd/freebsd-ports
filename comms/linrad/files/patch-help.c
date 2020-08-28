--- help.c.orig	2014-11-04 05:25:00.000000000 -0500
+++ help.c	2020-08-28 11:17:46.820070000 -0400
@@ -720,7 +720,7 @@
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%DATADIR%%errors.lir";
 line=3;
 write_from_msg_file(&line, lir_errcod, screen_mode, ERROR_VERNR);
 }  
@@ -730,7 +730,7 @@
 {
 int i, line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%DATADIR%%help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
