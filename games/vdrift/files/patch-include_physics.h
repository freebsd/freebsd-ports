--- include/physics.h	2009-01-15 23:50:36.000000000 -0500
+++ include/physics.h	2009-01-15 23:50:53.000000000 -0500
@@ -36,7 +36,7 @@
 	
 	list <btCollisionWorld::LocalRayResult> results;
 	
-	virtual	btScalar AddSingleResult(btCollisionWorld::LocalRayResult& rayResult,bool normalInWorldSpace)
+	virtual	btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult,bool normalInWorldSpace)
 	{
 		m_closestHitFraction = rayResult.m_hitFraction;
 		results.push_back(rayResult);
