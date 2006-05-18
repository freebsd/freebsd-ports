--- ./src/host.c.orig	Thu Nov  3 16:12:17 2005
+++ ./src/host.c	Tue May 16 14:36:05 2006
@@ -1046,7 +1046,7 @@
 // joe: same here
 //QuDos- enable/disable cmdhist.dat file creation, i don't need this feature
 	//if (con_initialized && (cmdhist = fopen("cmdhist.dat", "wb")))
-	if (con_initialized && cmdhist_file.value && (cmdhist = fopen("cmdhist.dat", "wb")))
+	if (con_initialized && (cmdhist = fopen(va("%s/cmdhist.dat", com_gamedir), "wb")))
 //QuDos-
 	{
 		for (i=0 ; i<64 ; i++)
