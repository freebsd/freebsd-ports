--- help.c.orig	2014-11-04 10:25:00 UTC
+++ help.c
@@ -720,7 +720,7 @@ else
   printf("\n%s",s);
   DEB"\n%s",s);
   }  
-msg_filename="errors.lir";
+msg_filename="%%PREFIX%%/share/linrad/errors.lir";
 line=3;
 write_from_msg_file(&line, lir_errcod, screen_mode, ERROR_VERNR);
 }  
@@ -730,7 +730,7 @@ void help_message(int msg_no)
 {
 int i, line;
 if(msg_no < 0)return;
-msg_filename="help.lir";
+msg_filename="%%PREFIX%%/share/linrad/help.lir";
 line=0;
 settextcolor(15);
 clear_screen();
