--- ./common.c.orig	Sat Jun 10 12:08:13 2006
+++ ./common.c	Sat Jun 10 12:08:13 2006
@@ -2221,7 +2221,10 @@
 		if ((userdir[j-1] == '\\') || (userdir[j-1] == '/'))
 			userdir[j-1] = 0;
 	}
+
+	strncpy (com_prefdir, userdir, j);
 	COM_AddGameFS (userdir);
+	Sys_mkdir(com_gamedir);
 #endif
 
 
