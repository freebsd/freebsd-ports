--- common.c.orig	Thu Aug 28 18:15:40 2003
+++ common.c	Thu Aug 28 18:16:04 2003
@@ -1512,7 +1512,7 @@
 	if ((i = COM_CheckParm ("-basedir")) && i < com_argc - 1)
 		Q_strncpyz (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		strcpy (com_basedir, ".");
+		strcpy (com_basedir, "%%%%BASEDIR%%%%");
 
 	for (i = 0; i < strlen(com_basedir); i++)
 		if (com_basedir[i] == '\\')
