--- rts/Sim/Misc/SimObjectIDPool.cpp.orig	2020-12-26 12:45:43 UTC
+++ rts/Sim/Misc/SimObjectIDPool.cpp
@@ -25,8 +25,8 @@ void SimObjectIDPool::Expand(unsigned int baseID, unsi
 	std::generate(newIDs.begin(), newIDs.begin() + numIDs, [&baseID]() { return (baseID++); });
 
 	// randomize so that Lua widgets can not easily determine counts
-	std::random_shuffle(newIDs.begin(), newIDs.begin() + numIDs, gsRNG);
-	std::random_shuffle(newIDs.begin(), newIDs.begin() + numIDs, gsRNG);
+	std::shuffle(newIDs.begin(), newIDs.begin() + numIDs, gsRNG);
+	std::shuffle(newIDs.begin(), newIDs.begin() + numIDs, gsRNG);
 
 	// lambda capture ("[n = baseID]() mutable { return (n++); }") requires std=c++14
 	baseID -= numIDs;
