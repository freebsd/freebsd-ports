--- sv_login.c.orig	Tue Jun  3 17:47:04 2003
+++ sv_login.c	Tue Jun  3 17:48:21 2003
@@ -244,7 +244,7 @@
 			continue;
 		}
 
-		if (!stricmp(accounts[i].login, Cmd_Argv(1)) || (use == use_ip && !stricmp(accounts[i].login, Cmd_Argv(2))))
+		if (!strcasecmp(accounts[i].login, Cmd_Argv(1)) || (use == use_ip && !strcasecmp(accounts[i].login, Cmd_Argv(2))))
 			break;
 
 		c++;
@@ -298,7 +298,7 @@
 		if (accounts[i].state == a_free)
 			continue;
 
-		if (!stricmp(accounts[i].login, Cmd_Argv(1)))
+		if (!strcasecmp(accounts[i].login, Cmd_Argv(1)))
 		{
 			if (accounts[i].inuse)
 				SV_Logout(&svs.clients[accounts[i].inuse -1]);
@@ -365,7 +365,7 @@
 		if (accounts[i].state == a_free)
 			continue;
 
-		if (!stricmp(accounts[i].login, Cmd_Argv(1)))
+		if (!strcasecmp(accounts[i].login, Cmd_Argv(1)))
 		{
 			if (block)
 			{
@@ -434,7 +434,7 @@
 			continue;
 
 		if (use == accounts[i].use &&
-			/*use == use_log && accounts[i].use == use_log && */!stricmp(log, accounts[i].login))
+			/*use == use_log && accounts[i].use == use_log && */!strcasecmp(log, accounts[i].login))
 		{
 			if (accounts[i].inuse && accounts[i].use == use_log)
 				return -1;
@@ -442,7 +442,7 @@
 			if (accounts[i].state == a_blocked)
 				return -2;
 
-			if (use == use_ip || !stricmp(pass, accounts[i].pass)) {
+			if (use == use_ip || !strcasecmp(pass, accounts[i].pass)) {
 				accounts[i].failures = 0;
 				accounts[i].inuse++;
 				return i+1;
