--- sv_main.c.orig	Tue Jun  3 17:53:39 2003
+++ sv_main.c	Tue Jun  3 17:56:11 2003
@@ -646,7 +646,7 @@
 			vip = SV_VIPbyIP(net_from);
 		
 		if (spectator_password.string[0] && 
-			stricmp(spectator_password.string, "none") &&
+			strcasecmp(spectator_password.string, "none") &&
 			strcmp(spectator_password.string, s) )
 		{	// failed
 			spass = false;
@@ -671,7 +671,7 @@
 			vip = SV_VIPbyIP(net_from);
 
 		if (!vip && password.string[0] && 
-			stricmp(password.string, "none") &&
+			strcasecmp(password.string, "none") &&
 			strcmp(password.string, s) )
 		{
 			Con_Printf ("%s:password failed\n", NET_AdrToString (net_from));
@@ -1403,13 +1403,13 @@
 {
 	int i;
 
-	if (!vip_password.string[0] || !stricmp(vip_password.string, "none"))
+	if (!vip_password.string[0] || !strcasecmp(vip_password.string, "none"))
 		return 0;
 
 	Cmd_TokenizeString(vip_password.string);
 
 	for (i = 0; i < Cmd_Argc(); i++)
-		if (!strcmp(Cmd_Argv(i), pass) && stricmp(Cmd_Argv(i), "none"))
+		if (!strcmp(Cmd_Argv(i), pass) && strcasecmp(Cmd_Argv(i), "none"))
 			return i+1;
 
 	return 0;
@@ -2205,7 +2205,7 @@
 			val = Info_ValueForKey (cl->userinfo, "name");
 		}
 
-		if (!val[0] || !stricmp(val, "console")) {
+		if (!val[0] || !strcasecmp(val, "console")) {
 			Info_SetValueForKey (cl->userinfo, "name", "unnamed", MAX_INFO_STRING);
 			val = Info_ValueForKey (cl->userinfo, "name");
 		}
@@ -2215,7 +2215,7 @@
 			for (i=0, client = svs.clients ; i<MAX_CLIENTS ; i++, client++) {
 				if (client->state != cs_spawned || client == cl)
 					continue;
-				if (!stricmp(client->name, val))
+				if (!strcasecmp(client->name, val))
 					break;
 			}
 			if (i != MAX_CLIENTS) { // dup name
