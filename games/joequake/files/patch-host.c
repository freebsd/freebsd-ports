--- host.c.orig	Wed Oct 26 10:21:22 2005
+++ host.c	Mon Jan 16 18:45:46 2006
@@ -969,6 +969,7 @@
 */
 void Host_Shutdown (void)
 {
+	char		cmdhist_path[MAX_OSPATH];
 	int		i, j;
 	FILE		*cmdhist;
 	cmdhistory_t	cmdhistory;
@@ -989,7 +990,8 @@
 	Host_WriteConfiguration ();
 	IPLog_WriteLog ();
 
-	if (con_initialized && (cmdhist = fopen("joequake/cmdhist.dat", "wb")))
+	snprintf(cmdhist_path, sizeof(cmdhist_path), "%s/cmdhist.dat", com_gamedir);
+	if (con_initialized && (cmdhist = fopen(cmdhist_path, "wb")))
 	{
 		for (i=0 ; i<64 ; i++)
 			for (j=0 ; j<MAXCMDLINE ; j++)
