--- source/ogre/common/Terrain.cpp.orig	2022-11-11 19:35:22 UTC
+++ source/ogre/common/Terrain.cpp
@@ -202,8 +202,12 @@ if (bTer)
 		//  sync load since we want everything in place when we start
 		mTerrainGroup->loadAllTerrains(true);
 
-		auto tsm = mTerrainGroup->getTerrainSlots();
-		terrain = tsm[0]->instance;
+		TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();
+		while (ti.hasMoreElements())
+		{
+			terrain = ti.getNext()->instance;
+			terrain->setVisibilityFlags(RV_Terrain);
+		}
 
 		mTerrainGroup->freeTemporaryResources();
 	}
