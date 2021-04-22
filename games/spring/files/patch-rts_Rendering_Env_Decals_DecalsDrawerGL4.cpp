--- rts/Rendering/Env/Decals/DecalsDrawerGL4.cpp.orig	2021-01-01 19:08:25 UTC
+++ rts/Rendering/Env/Decals/DecalsDrawerGL4.cpp
@@ -338,7 +338,7 @@ void CDecalsDrawerGL4::DetectMaxDecals()
 	decals.resize(maxDecals);
 	freeIds.resize(maxDecals - 1); // idx = 0 is invalid, so -1
 	std::iota(freeIds.begin(), freeIds.end(), 1); // start with 1, 0 is illegal
-	std::random_shuffle(freeIds.begin(), freeIds.end(), guRNG);
+	std::shuffle(freeIds.begin(), freeIds.end(), guRNG);
 	groups.reserve(maxDecalGroups);
 }
 
