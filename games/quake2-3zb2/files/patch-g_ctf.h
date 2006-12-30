--- ./g_ctf.h.orig	Sat Dec 30 19:09:03 2006
+++ ./g_ctf.h	Sat Dec 30 19:09:23 2006
@@ -82,7 +82,7 @@
 void CTFAssignTeam(gclient_t *who);
 edict_t *SelectCTFSpawnPoint (edict_t *ent);
 qboolean CTFPickup_Flag(edict_t *ent, edict_t *other);
-qboolean CTFDrop_Flag(edict_t *ent, gitem_t *item);
+void CTFDrop_Flag(edict_t *ent, gitem_t *item); //was qboolean 
 void CTFEffects(edict_t *player);
 void CTFCalcScores(void);
 void SetCTFStats(edict_t *ent);
@@ -133,4 +133,4 @@
 
 void SP_trigger_teleport (edict_t *ent);
 void SP_info_teleport_destination (edict_t *ent);
-#endif
\ No newline at end of file
+#endif
