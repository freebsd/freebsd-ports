--- utils/newmail.c.orig	Sat Nov 23 21:35:27 2002
+++ utils/newmail.c	Sat Nov 23 21:35:59 2002
@@ -238,7 +238,7 @@
      print_prefix = 0,		/* force printing of prefix	    */
      current_folder = 0;	/* struct pointer for looping       */
 FILE	*fd = NULL;		/* fd to use to read folders	    */
-FILE	*debugfile = stderr;
+FILE	*debugfile;
 
 #ifdef PIDCHECK
 int  parent_pid;		/* See if sucide should be attempt  */
@@ -281,6 +281,8 @@
 #ifdef I_LOCALE
 	setlocale(LC_ALL, "");
 #endif
+
+	debugfile = stderr;
 
 	elm_msg_cat = catopen("elm2.4", 0);
 
