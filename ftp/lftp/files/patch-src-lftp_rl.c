--- src/lftp_rl.c.orig	Tue Oct 18 11:21:22 2005
+++ src/lftp_rl.c	Fri Oct 21 21:55:00 2005
@@ -191,9 +191,9 @@
    if(!lftp_history_file)
    {
       const char *home=get_lftp_home();
+      const char *add="/rl_history";
       if(!home)
 	 return;
-      const char *add="/rl_history";
       lftp_history_file=(char*)malloc(strlen(home)+strlen(add)+1);
       strcat(strcpy(lftp_history_file,home),add);
    }
