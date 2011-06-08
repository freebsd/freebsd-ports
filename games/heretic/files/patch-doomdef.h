--- doomdef.h.ori	Sun Mar  4 15:43:44 2007
+++ doomdef.h	Sun Mar  4 15:57:04 2007
@@ -681,6 +681,7 @@
   short	ticdup  __PACKED__ ;			     /* 1 = no duplication, 2-5 = dup for slow nets */
   short	extratics  __PACKED__ ;		     /* 1 = send a backup tic in every packet */
   short	deathmatch  __PACKED__ ;		     /* 1 = deathmatch */
+  short	respawnartifacts __PACKED__ ;        /* respawn the artifacts? 1=yes */
   short	savegame  __PACKED__ ;		     /* -1 = new game, 0-5 = load savegame */
   short	episode  __PACKED__ ;		     /* 1-3 */
   short	map  __PACKED__ ;			     /* 1-9 */
@@ -753,6 +754,8 @@
 extern boolean cdrom;       /* true if cd-rom mode active ("-cdrom") */
 
 extern boolean deathmatch;  /* only if started as net death */
+
+extern boolean respawnartifacts; /* respawn the artifacts */
 
 extern boolean netgame;     /* only true if >1 player */
 
