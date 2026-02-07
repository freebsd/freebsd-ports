--- p_inter.c.orig	2000-01-07 17:58:53 UTC
+++ p_inter.c
@@ -477,8 +477,10 @@ boolean P_GiveArtifact(player_t *player,
 void P_SetDormantArtifact(mobj_t *arti)
 {
   arti->flags &= ~MF_SPECIAL;
-  if(deathmatch && (arti->type != MT_ARTIINVULNERABILITY)
-     && (arti->type != MT_ARTIINVISIBILITY))
+  if(
+     (deathmatch && (arti->type != MT_ARTIINVULNERABILITY)
+      && (arti->type != MT_ARTIINVISIBILITY))
+     || (respawnartifacts) )
     {
       P_SetMobjState(arti, S_DORMANTARTI1);
     }
