--- ./g_ctf.c.orig	Sat Dec 30 19:09:03 2006
+++ ./g_ctf.c	Sat Dec 30 19:09:23 2006
@@ -378,12 +378,12 @@
 	float	range, range1, range2;
 	char	*cname;
 
-	if (ent->client->resp.ctf_state != CTF_STATE_START)
+	if (ent->client->resp.ctf_state != CTF_STATE_START) {
 		if ( (int)(dmflags->value) & DF_SPAWN_FARTHEST)
 			return SelectFarthestDeathmatchSpawnPoint ();
 		else
 			return SelectRandomDeathmatchSpawnPoint ();
-
+	}
 	ent->client->resp.ctf_state = CTF_STATE_PLAYING;
 
 	switch (ent->client->resp.ctf_team) {
@@ -806,7 +806,7 @@
 		dropped->touch = CTFDropFlagTouch;
 	}
 }
-
+#if 0
 qboolean CTFDrop_Flag(edict_t *ent, gitem_t *item)
 {
 	if (rand() & 1) 
@@ -821,7 +821,21 @@
 	}
 	return false;
 }
-
+#else
+void CTFDrop_Flag(edict_t *ent, gitem_t *item)
+{
+	if (rand() & 1) 
+	{
+		if(!(ent->svflags & SVF_MONSTER))
+		gi.cprintf(ent, PRINT_HIGH, "Only lusers drop flags.\n");
+	}
+	else
+	{
+		if(!(ent->svflags & SVF_MONSTER))
+		gi.cprintf(ent, PRINT_HIGH, "Winners don't drop flags.\n");
+	}
+}
+#endif
 static void CTFFlagThink(edict_t *ent)
 {
 	if (ent->solid != SOLID_NOT)
@@ -3004,10 +3018,11 @@
 	CurrentIndex = 0;
 	memset(Route,0,sizeof(Route));
 	memset(code,0,8);
-
-	if(!ctf->value) sprintf(name,".\\%s\\chdtm\\%s.chn",gamepath->string,level.mapname);
-	else sprintf(name,".\\%s\\chctf\\%s.chf",gamepath->string,level.mapname);
-
+	if(!ctf->value) 
+		sprintf(name,"%s/chdtm/%s.chn",gamepath->string,level.mapname);
+	else 
+		sprintf(name,"%s/chctf/%s.chf",gamepath->string,level.mapname);
+		
 	fpout = fopen(name,"rb");
 	if(fpout == NULL)
 	{
@@ -3224,4 +3239,4 @@
 		if(geti2 != NULL) geti2->client->zc.ctfstate = CTFS_OFFENCER;
 	}
 ///	gi.bprintf(PRINT_HIGH,"Called!!!!\n");
-}
\ No newline at end of file
+}
