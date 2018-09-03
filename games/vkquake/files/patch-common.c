--- common.c.orig	2017-09-09 21:55:23 UTC
+++ common.c
@@ -2231,7 +2231,7 @@ void COM_InitFilesystem (void) //johnfitz -- modified 
 	if (i && i < com_argc-1)
 		q_strlcpy (com_basedir, com_argv[i + 1], sizeof(com_basedir));
 	else
-		q_strlcpy (com_basedir, host_parms->basedir, sizeof(com_basedir));
+		q_strlcpy (com_basedir, DATADIR, sizeof(com_basedir));
 
 	j = strlen (com_basedir);
 	if (j < 1) Sys_Error("Bad argument to -basedir");
