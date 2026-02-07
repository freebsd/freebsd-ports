--- common.c.orig	2020-09-30 11:25:10 UTC
+++ common.c
@@ -2221,7 +2221,10 @@ void COM_InitFilesystem (void)
 		if ((userdir[j-1] == '\\') || (userdir[j-1] == '/'))
 			userdir[j-1] = 0;
 	}
+
+	strncpy (com_prefdir, userdir, j);
 	COM_AddGameFS (userdir);
+	Sys_mkdir(com_gamedir);
 #endif
 
 
