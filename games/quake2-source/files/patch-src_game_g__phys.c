--- src/game/g_phys.c.orig	Tue Mar 15 22:15:11 2005
+++ src/game/g_phys.c	Tue Mar 15 22:16:41 2005
@@ -356,7 +356,13 @@
 		mask = MASK_SOLID;
 
 	trace = gi.trace (start, ent->mins, ent->maxs, end, ent, mask);
-	
+
+	if (trace.startsolid || trace.allsolid)
+	{
+		mask ^= CONTENTS_DEADMONSTER;
+		trace = gi.trace (start, ent->mins, ent->maxs, end, ent, mask);
+	}
+
 	VectorCopy (trace.endpos, ent->s.origin);
 	gi.linkentity (ent);
 
