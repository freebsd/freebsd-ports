--- ./code/renderer/tr_light.c.orig	Tue Jul 18 17:53:12 2006
+++ ./code/renderer/tr_light.c	Sun Dec 17 13:16:04 2006
@@ -222,21 +222,21 @@
 		// decode Y as sin( lat ) * sin( long )
 		// decode Z as cos( long )
 
-		(int)ent->ambientLight[0] /= (int)10;
-		(int)ent->ambientLight[1] /= (int)10;
-		(int)ent->ambientLight[2] /= (int)10;
+		ent->ambientLight[0] /= (int)10;
+		ent->ambientLight[1] /= (int)10;
+		ent->ambientLight[2] /= (int)10;
 
-		(int)ent->directedLight[0] /= (int)10;
-		(int)ent->directedLight[1] /= (int)10;
-		(int)ent->directedLight[2] /= (int)10;
+		ent->directedLight[0] /= (int)10;
+		ent->directedLight[1] /= (int)10;
+		ent->directedLight[2] /= (int)10;
 
-		(int)ent->ambientLight[0] *= (int)10;
-		(int)ent->ambientLight[1] *= (int)10;
-		(int)ent->ambientLight[2] *= (int)10;
+		ent->ambientLight[0] *= (int)10;
+		ent->ambientLight[1] *= (int)10;
+		ent->ambientLight[2] *= (int)10;
 
-		(int)ent->directedLight[0] *= (int)10;
-		(int)ent->directedLight[1] *= (int)10;
-		(int)ent->directedLight[2] *= (int)10;
+		ent->directedLight[0] *= (int)10;
+		ent->directedLight[1] *= (int)10;
+		ent->directedLight[2] *= (int)10;
 
 
 		normal[0] = tr.sinTable[(lat+(FUNCTABLE_SIZE/4))&FUNCTABLE_MASK] * tr.sinTable[lng];
