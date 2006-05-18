--- ./game/g_phys.c.orig	Tue May 16 15:20:10 2006
+++ ./game/g_phys.c	Tue May 16 15:20:10 2006
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
 
