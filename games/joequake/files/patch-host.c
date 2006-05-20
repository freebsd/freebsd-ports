--- ./host.c.orig	Sun Apr 16 15:42:16 2006
+++ ./host.c	Sat May 20 10:00:24 2006
@@ -964,6 +964,7 @@
 */
 void Host_Shutdown (void)
 {
+	char		cmdhist_path[MAX_OSPATH];
 	int		i, j;
 	FILE		*cmdhist;
 	cmdhistory_t	cmdhistory;
@@ -984,7 +985,8 @@
 	Host_WriteConfiguration ();
 	IPLog_WriteLog ();
 
-	if (con_initialized && (cmdhist = fopen("joequake/cmdhist.dat", "wb")))
+	snprintf(cmdhist_path, sizeof(cmdhist_path), "%s/cmdhist.dat", com_gamedir);
+	if (con_initialized && (cmdhist = fopen(cmdhist_path, "wb")))
 	{
 		for (i=0 ; i<64 ; i++)
 			for (j=0 ; j<MAXCMDLINE ; j++)
