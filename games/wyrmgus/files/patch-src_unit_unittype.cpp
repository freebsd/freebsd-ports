--- src/unit/unittype.cpp.orig	2015-11-10 20:52:37 UTC
+++ src/unit/unittype.cpp
@@ -761,13 +761,13 @@ CUnitType::CUnitType() :
 	//Wyrmgus end
 	memset(ResInfo, 0, sizeof(ResInfo));
 	//Wyrmgus start
-	memset(VarInfo, NULL, sizeof(VarInfo));
+	memset(VarInfo, 0, sizeof(VarInfo));
 	memset(Drops, 0, sizeof(Drops));
 //	memset(ImproveIncomes, 0, sizeof(ImproveIncomes));
 	//Wyrmgus end
 	memset(MissileOffsets, 0, sizeof(MissileOffsets));
 	//Wyrmgus start
-	memset(ShieldAnimation, NULL, sizeof(ShieldAnimation));
+	memset(ShieldAnimation, 0, sizeof(ShieldAnimation));
 	//Wyrmgus end
 }
 
