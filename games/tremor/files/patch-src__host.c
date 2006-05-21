--- ./src/host.c.orig	Sat Mar 26 21:14:38 2005
+++ ./src/host.c	Tue May 16 14:59:52 2006
@@ -987,7 +987,7 @@
 	Host_WriteConfiguration ();
 
 // joe: same here
-	if (con_initialized && (cmdhist = fopen("cmdhist.dat", "wb")))
+	if (con_initialized && (cmdhist = fopen(va("%s/cmdhist.dat", com_gamedir), "wb")))
 	{
 		for (i=0 ; i<64 ; i++)
 			for (j=0 ; j<MAXCMDLINE ; j++)
