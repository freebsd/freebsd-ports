--- ./keys.c.orig	Sat Mar 25 15:00:04 2006
+++ ./keys.c	Sat May 20 10:00:24 2006
@@ -808,11 +808,13 @@
 void Key_Init (void)
 {
 // joe: added stuff from [sons]Quake
+	char		cmdhist_path[MAX_OSPATH];
 	int		i, j;
 	FILE		*cmdhist;
 	cmdhistory_t	cmdhistory;
 
-	if ((cmdhist = fopen("joequake/cmdhist.dat", "rb")))
+	snprintf(cmdhist_path, sizeof(cmdhist_path), "%s/cmdhist.dat", com_gamedir);
+	if ((cmdhist = fopen(cmdhist_path, "rb")))
 	{
 		fread (&cmdhistory, sizeof(cmdhistory_t), 1, cmdhist);
 		fclose (cmdhist);
