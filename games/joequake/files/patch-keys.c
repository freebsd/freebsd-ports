--- keys.c.orig	Fri Oct 21 18:30:06 2005
+++ keys.c	Mon Jan 16 18:47:12 2006
@@ -783,11 +783,13 @@
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
