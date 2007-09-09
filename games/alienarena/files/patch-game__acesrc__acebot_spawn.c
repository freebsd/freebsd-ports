--- ./game/acesrc/acebot_spawn.c.orig	Wed Apr 25 18:22:21 2007
+++ ./game/acesrc/acebot_spawn.c	Sat Jul 21 09:34:40 2007
@@ -126,11 +126,11 @@
 
 //bots and configurations will be loaded level specific
 	if (((int)(dmflags->value) & DF_SKINTEAMS) || ctf->value || tca->value || cp->value)
-		strcpy(bot_filename, "botinfo/team.tmp");
+		strcpy(bot_filename, BOTDIR"/botinfo/team.tmp");
 	else if(sv_custombots->value)
-		sprintf(bot_filename, "botinfo/custom%i.tmp", sv_custombots->integer);
+		sprintf(bot_filename, BOTDIR"/botinfo/custom%i.tmp", sv_custombots->integer);
 	else
-		sprintf(bot_filename, "botinfo/%s.tmp", level.mapname);
+		sprintf(bot_filename, BOTDIR"/botinfo/%s.tmp", level.mapname);
 
 	if((pIn = fopen(bot_filename, "rb" )) == NULL)
 		return; // bail
@@ -543,7 +543,7 @@
 		//if not a respawn, load bot configuration file(specific to each bot)
 		info = Info_ValueForKey (bot->client->pers.userinfo, "name");
  
-		sprintf(bot_configfilename, "botinfo/%s.cfg", info);
+		sprintf(bot_configfilename, BOTDIR"/botinfo/%s.cfg", info);
 		ACECO_ReadConfig(bot_configfilename);
 
 		//set config items
