--- cl_slist.c.orig	Sat Apr 22 13:34:10 2006
+++ cl_slist.c	Thu May  4 22:03:17 2006
@@ -21,10 +21,13 @@
 
 #include "quakedef.h"
 
+char		slfile[MAX_OSPATH];
 server_entry_t	slist[MAX_SERVER_LIST];
 
 void SList_Init (void)
 {
+	Q_strncpyz(slfile, com_gamedir, sizeof(slfile));
+	strncat(slfile, "/servers.lst", sizeof(slfile)-strlen(slfile)-1);
 	memset (&slist, 0, sizeof(slist));
 }
 
@@ -36,7 +39,7 @@
 	if (!slist[0].server)
 		return;
 
-	if (!(f = fopen("servers.lst", "wt")))
+	if (!(f = fopen(slfile, "wt")))
 	{
 		Con_DPrintf ("Couldn't open servers.lst\n");
 		return;
@@ -115,7 +118,7 @@
 	char	line[128], *desc, *addr;
 	FILE	*f;
 
-	if (!(f = fopen("servers.lst", "rt")))
+	if (!(f = fopen(slfile, "rt")))
 		return;
 
 	count = len = 0;
