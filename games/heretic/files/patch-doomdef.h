--- doomdef.h.orig	2000-05-01 23:42:01 UTC
+++ doomdef.h
@@ -681,6 +681,7 @@ typedef struct
   short	ticdup  __PACKED__ ;			     /* 1 = no duplication, 2-5 = dup for slow nets */
   short	extratics  __PACKED__ ;		     /* 1 = send a backup tic in every packet */
   short	deathmatch  __PACKED__ ;		     /* 1 = deathmatch */
+  short	respawnartifacts __PACKED__ ;        /* respawn the artifacts? 1=yes */
   short	savegame  __PACKED__ ;		     /* -1 = new game, 0-5 = load savegame */
   short	episode  __PACKED__ ;		     /* 1-3 */
   short	map  __PACKED__ ;			     /* 1-9 */
@@ -754,6 +755,8 @@ extern boolean cdrom;       /* true if c
 
 extern boolean deathmatch;  /* only if started as net death */
 
+extern boolean respawnartifacts; /* respawn the artifacts */
+
 extern boolean netgame;     /* only true if >1 player */
 
 extern boolean playeringame[MAXPLAYERS];
