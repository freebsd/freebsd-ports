--- common.c.orig	Thu Feb  5 01:05:19 2004
+++ common.c	Thu Feb  5 01:09:07 2004
@@ -1006,7 +1006,7 @@
 	if ((i = COM_CheckParm ("-basedir")) && i < com_argc - 1)
 		Q_strncpyz (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		getcwd(com_basedir, sizeof(com_basedir) - 1);
+		strcpy(com_basedir, "%%BASEDIR%%");
 
 	for (i = 0; i < strlen(com_basedir); i++)
 		if (com_basedir[i] == '\\')
