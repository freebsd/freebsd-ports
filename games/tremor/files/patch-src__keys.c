--- ./src/keys.c.orig	Fri Oct 29 19:15:24 2004
+++ ./src/keys.c	Tue May 16 14:59:52 2006
@@ -674,7 +674,7 @@
 	FILE		*cmdhist;
 	cmdhistory_t	cmdhistory;
 
-	if ((cmdhist = fopen("cmdhist.dat", "rb")))
+	if ((cmdhist = fopen(va("%s/cmdhist.dat", com_gamedir), "rb")))
 	{
 		fread (&cmdhistory, sizeof(cmdhistory_t), 1, cmdhist);
 		fclose (cmdhist);
