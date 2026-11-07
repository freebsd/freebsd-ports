--- slideshow/source/engine/box2dtools.cxx.orig	2026-11-07 13:31:47.813777000 +0100
+++ slideshow/source/engine/box2dtools.cxx	2026-11-07 13:33:59.828751000 +0100
@@ -307,7 +307,7 @@
 
     b2ChainDef aChainDef = b2DefaultChainDef();
     aChainDef.points = aEdgePoints;
-    aChainDef.count = 4;
+    aChainDef.pointCount = 4;
     aChainDef.isLoop = true;
     b2CreateChain(aBody, &aChainDef);
 #else
@@ -1002,7 +1002,7 @@
         b2Shape_SetRestitution(aShapeId, static_cast<float>(fRestitution));
     }
     // without resetting the massdata of the body, density change won't take effect
-    b2Body_ApplyMassFromShapes(*mpBox2DBody);
+    b2Body_UpdateMassFromShapes(*mpBox2DBody);
 #else
     // density and restitution have to be set for each fixture of the body individually
     for (b2Fixture* pFixture = mpBox2DBody->GetFixtureList(); pFixture;
