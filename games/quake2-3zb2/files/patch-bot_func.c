--- ./bot_func.c.orig	Sat Dec 30 19:09:03 2006
+++ ./bot_func.c	Sat Dec 30 19:09:23 2006
@@ -84,8 +84,8 @@
 	botlist = gi.cvar ("botlist", "default", CVAR_SERVERINFO | CVAR_LATCH);
 	gamepath = gi.cvar ("game", "0", CVAR_NOSET);
 
-	//load info
-	sprintf(Buff,".\\%s\\3ZBconfig.cfg",gamepath->string);
+	//load info	
+	sprintf(Buff,"%s/3ZBConfig.cfg",gamepath->string);
 	fp = fopen(Buff,"rt");
 	if(fp == NULL)
 	{
@@ -336,7 +336,6 @@
 	gclient_t	*client;
 	char		pinfo[200];
 	int			index;
-	int			i;
 
 	index = ent-g_edicts-1;
 	ent->client = &game.clients[index];
