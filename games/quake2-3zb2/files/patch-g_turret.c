--- ./g_turret.c.orig	Sat Dec 30 19:09:03 2006
+++ ./g_turret.c	Sat Dec 30 19:09:23 2006
@@ -253,8 +253,11 @@
 */
 
 void infantry_die (edict_t *self, edict_t *inflictor, edict_t *attacker, int damage);
+/* 
 void infantry_stand (edict_t *self);
-void monster_use (edict_t *self, edict_t *other, edict_t *activator);
+void monster_use (edict_t *self, edict_t *other, edict_t *activator); 
+*/ 
+
 
 void turret_driver_die (edict_t *self, edict_t *inflictor, edict_t *attacker, int damage, vec3_t point)
 {
@@ -273,10 +276,13 @@
 	self->target_ent->owner = NULL;
 	self->target_ent->teammaster->owner = NULL;
 
-	infantry_die (self, inflictor, attacker, damage);
+//	infantry_die (self, inflictor, attacker, damage);
+
 }
 
-qboolean FindTarget (edict_t *self);
+
+//qboolean FindTarget (edict_t *self);
+
 
 void turret_driver_think (edict_t *self)
 {
@@ -291,8 +297,11 @@
 
 	if (!self->enemy)
 	{
+		/* 
 		if (!FindTarget (self))
-			return;
+			return; 
+		*/
+
 		self->monsterinfo.trail_time = level.time;
 		self->monsterinfo.aiflags &= ~AI_LOST_SIGHT;
 	}
@@ -385,7 +394,8 @@
 	self->viewheight = 24;
 
 	self->die = turret_driver_die;
-	self->monsterinfo.stand = infantry_stand;
+	
+//	self->monsterinfo.stand = infantry_stand;
 
 	self->flags |= FL_NO_KNOCKBACK;
 
@@ -394,7 +404,9 @@
 	self->svflags |= SVF_MONSTER;
 	self->s.renderfx |= RF_FRAMELERP;
 	self->takedamage = DAMAGE_AIM;
-	self->use = monster_use;
+
+//	self->use = monster_use;
+
 	self->clipmask = MASK_MONSTERSOLID;
 	VectorCopy (self->s.origin, self->s.old_origin);
 	self->monsterinfo.aiflags |= AI_STAND_GROUND|AI_DUCKED;
