--- ./src/keys.c.orig	Thu Nov  3 16:14:02 2005
+++ ./src/keys.c	Tue May 16 14:36:16 2006
@@ -663,7 +663,7 @@
 
 //QuDos- enable/disable cmdhist.dat file creation, i don't need this feature
 //	if ((cmdhist = fopen ("cmdhist.dat", "rb")))
-	if (cmdhist_file.value && (cmdhist = fopen("cmdhist.dat", "rb")))
+	if (cmdhist = fopen(va("%s/cmdhist.dat", com_gamedir), "rb"))
 //QuDos-
 	{
 		fread (&cmdhistory, sizeof(cmdhistory_t), 1, cmdhist);
