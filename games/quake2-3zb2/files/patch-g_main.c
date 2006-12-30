--- ./g_main.c.orig	Sat Dec 30 19:09:03 2006
+++ ./g_main.c	Sat Dec 30 19:09:23 2006
@@ -62,6 +62,7 @@
 float	spawncycle;
 float	ctfjob_update;
 //ponpoko
+cvar_t	*botchat;
 
 void SpawnEntities (char *mapname, char *entities, char *spawnpoint);
 void ClientThink (edict_t *ent, usercmd_t *cmd);
@@ -209,7 +210,8 @@
 	
 	if(!maplist->string) return;
 
-	sprintf(Buff,".\\%s\\3ZBMAPS.LST",gamepath->string);
+	sprintf(Buff,"%s/3ZBMaps.lst",gamepath->string);
+	
 	fp = fopen(Buff,"r");
 	if(fp == NULL) return;
 	
