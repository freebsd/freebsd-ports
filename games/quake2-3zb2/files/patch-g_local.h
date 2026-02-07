--- ./g_local.h.orig	Sat Dec 30 19:09:03 2006
+++ ./g_local.h	Sat Dec 30 19:09:23 2006
@@ -586,10 +586,10 @@
 extern	cvar_t	*zigmode;
 extern	float	spawncycle;
 //ponpoko
-
 //ZOID
 extern	qboolean	is_quad;
 //ZOID
+extern	cvar_t	*botchat;
 
 #define world	(&g_edicts[0])
 
@@ -636,6 +636,13 @@
 extern	field_t fields[];
 extern	gitem_t	itemlist[];
 
+//
+// bot.c
+//
+
+void bFakeChat(edict_t *bot);
+void bInsult(edict_t *bot, edict_t *loser);
+void bTaunt(edict_t *bot, edict_t *other);
 
 //
 // g_cmds.c
@@ -1246,12 +1253,16 @@
 	// common data blocks
 	moveinfo_t		moveinfo;
 	monsterinfo_t	monsterinfo;
-
+	
 	// RAFAEL
 	int			orders;
+	
+	float last_insult;
+ 	float last_taunt;
+ 	float last_chat;
 };
 
 //ZOID
 #include "g_ctf.h"
 //ZOID
-#endif
\ No newline at end of file
+#endif
