--- ./server/sv_main.c.orig	Tue May 16 15:20:10 2006
+++ ./server/sv_main.c	Tue May 16 15:20:10 2006
@@ -445,8 +445,9 @@
 		return;
 	}
 
-	strncpy (userinfo, Cmd_Argv(4), sizeof(userinfo)-1);
-	userinfo[sizeof(userinfo) - 1] = 0;
+	// sku - reserve 32 bytes for the IP address
+	strncpy (userinfo, Cmd_Argv(4), sizeof(userinfo)-32);
+	userinfo[sizeof(userinfo) - 32] = 0;
 
 	//check it is not overflowed, save enough bytes for /ip/111.222.333.444:55555
 	if (strlen(userinfo) + 25 >= sizeof(userinfo)-1)
@@ -502,8 +503,11 @@
 		{
 			if (NET_CompareBaseAdr (net_from, svs.challenges[i].adr))
 			{
-				if (challenge == svs.challenges[i].challenge)
+				// sku - ignore zero challenges
+				if( svs.challenges[i].challenge && challenge == svs.challenges[i].challenge ) {
+					svs.challenges[i].challenge = 0;
 					break;		// good
+				}
 				Netchan_OutOfBandPrint (NS_SERVER, adr, "print\nBad challenge.\n");
 				return;
 			}
@@ -588,12 +592,6 @@
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
