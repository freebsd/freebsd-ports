--- server/sv_main.c.orig	Fri Mar 30 23:15:20 2007
+++ server/sv_main.c	Fri Mar 30 23:16:36 2007
@@ -450,8 +450,9 @@
 		return;
 	}
 
-	strncpy (userinfo, Cmd_Argv(4), sizeof(userinfo)-1);
-	userinfo[sizeof(userinfo) - 1] = 0;
+	// sku - reserve 32 bytes for the IP address
+	strncpy (userinfo, Cmd_Argv(4), sizeof(userinfo)-32);
+	userinfo[sizeof(userinfo) - 32] = 0;
 
 	//check it is not overflowed, save enough bytes for /ip/111.222.333.444:55555
 	if (strlen(userinfo) + 25 >= sizeof(userinfo)-1)
@@ -595,12 +596,6 @@
 			Netchan_OutOfBandPrint (NS_SERVER, adr, "print\nConnection refused.\n" );
 		Com_DPrintf ("Game rejected a connection.\n");
 		return;
-	}
-
-	if (userinfo[MAX_INFO_STRING-1])
-	{
-		//probably already crashed by now but worth a try
-		Com_Error (ERR_FATAL, "Userinfo string length overflowed after ClientConnect");
 	}
 
 	// parse some info from the info strings
