--- p_inter.c.ori	Sun Mar  4 15:38:51 2007
+++ p_inter.c	Sun Mar  4 15:41:50 2007
@@ -477,8 +477,10 @@
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
