--- common.c.orig	2022-07-08 05:51:08 UTC
+++ common.c
@@ -2233,7 +2233,7 @@ void COM_InitFilesystem (void) // johnfitz -- modified
 	if (i && i < com_argc - 1)
 		q_strlcpy (com_basedir, com_argv[i + 1], sizeof (com_basedir));
 	else
-		q_strlcpy (com_basedir, host_parms->basedir, sizeof (com_basedir));
+		q_strlcpy (com_basedir, DATADIR, sizeof (com_basedir));
 
 	j = strlen (com_basedir);
 	if (j < 1)
