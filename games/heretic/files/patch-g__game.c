--- g_game.c.orig	2000-05-01 23:54:51 UTC
+++ g_game.c
@@ -91,6 +91,7 @@ int             starttime;              
 boolean         viewactive;
 
 boolean         deathmatch;             /* only if started as net death */
+boolean		respawnartifacts;       /* respawning Artifacts */
 boolean         netgame;                /* only true if packets are broadcast */
 boolean         playeringame[MAXPLAYERS];
 player_t        players[MAXPLAYERS];
@@ -122,6 +123,7 @@ extern char* homedir;
 long            key_right, key_left, key_up, key_down;
 long            key_strafeleft, key_straferight;
 long            key_fire, key_use, key_strafe, key_speed;
+long            key_health, key_tomeofpower, key_egg, key_firebomb;
 long            key_flyup, key_flydown, key_flycenter;
 long            key_lookup, key_lookdown, key_lookcenter;
 long            key_invleft, key_invright, key_useartifact;
@@ -361,13 +363,34 @@ void G_BuildTiccmd (ticcmd_t *cmd)
 	    }
 	}
     }
-  if(gamekeydown[127] && !cmd->arti
+  if(gamekeydown[key_tomeofpower] && !cmd->arti
      && !players[consoleplayer].powers[pw_weaponlevel2])
     {
-      gamekeydown[127] = false;
+      gamekeydown[key_tomeofpower] = false;
       cmd->arti = arti_tomeofpower;
     }
-  
+  // Health by key:
+  if(gamekeydown[key_health] && !cmd->arti)
+    {
+      gamekeydown[key_health] = false;
+      cmd->arti = arti_health;
+    }
+
+  // Egg by key:
+  if(gamekeydown[key_egg] && !cmd->arti)
+    {
+      gamekeydown[key_egg] = false;
+      cmd->arti = arti_egg;
+    }
+
+  // Timebombe by key:
+  if(gamekeydown[key_firebomb] && !cmd->arti)
+    {
+      gamekeydown[key_firebomb] = false;
+      cmd->arti = arti_firebomb;
+    }
+
+
   /*
    * buttons
    */
