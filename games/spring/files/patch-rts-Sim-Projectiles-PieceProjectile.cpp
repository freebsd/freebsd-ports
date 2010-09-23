--- rts/Sim/Projectiles/PieceProjectile.cpp.orig	2010-09-06 16:16:18.000000000 +0400
+++ rts/Sim/Projectiles/PieceProjectile.cpp	2010-09-23 03:36:30.000000000 +0400
@@ -64,7 +64,7 @@
 CPieceProjectile::CPieceProjectile(const float3& pos, const float3& speed, LocalModelPiece* lmp, int f, CUnit* owner, float radius):
 	CProjectile(pos, speed, owner, true, false, true),
 	flags(f),
-	dispList(lmp? lmp->displist: 0),
+	dispList(),
 	omp(NULL),
 	spinAngle(0.0f),
 	alphaThreshold(0.1f),
