--- common.c.orig	Sun Mar 14 13:16:07 2004
+++ common.c	Sun Mar 14 13:17:40 2004
@@ -2221,6 +2221,8 @@
 		if ((userdir[j-1] == '\\') || (userdir[j-1] == '/'))
 			userdir[j-1] = 0;
 	}
+
+	strncpy (com_prefdir, userdir, j);
 	COM_AddGameFS (userdir);
 #endif
 
