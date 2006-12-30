--- ./p_client.c.orig	Sat Dec 30 19:09:03 2006
+++ ./p_client.c	Sat Dec 30 19:09:23 2006
@@ -388,6 +388,12 @@
 				gi.bprintf (PRINT_MEDIUM,"%s %s %s%s\n", self->client->pers.netname, message, attacker->client->pers.netname, message2);
 				if (deathmatch->value)
 				{
+					if (botchat->value) {
+						if (attacker->client && attacker != self) {
+ 							bTaunt(attacker, self);
+ 							bInsult(attacker, self); 
+						}
+					}
 					if (ff)
 						attacker->client->resp.score--;
 					else
@@ -1342,7 +1348,10 @@
 	VectorCopy (spawn_origin, ent->s.origin);
 	ent->s.origin[2] += 1;	// make sure off ground
 	VectorCopy (ent->s.origin, ent->s.old_origin);
-
+	ent->last_insult = level.time;
+ 	ent->last_taunt = level.time;
+ 	ent->last_chat = level.time;
+	
 	// set the delta angle
 	for (i=0 ; i<3 ; i++)
 		client->ps.pmove.delta_angles[i] = ANGLE2SHORT(spawn_angles[i] - client->resp.cmd_angles[i]);
