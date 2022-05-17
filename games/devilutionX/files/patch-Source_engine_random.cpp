https://github.com/diasurgical/devilutionX/pull/4588

--- Source/engine/random.cpp.orig	2022-04-25 02:21:41 UTC
+++ Source/engine/random.cpp
@@ -29,7 +29,8 @@ uint32_t GetLCGEngineState()
 
 int32_t GetRndSeed()
 {
-	return abs(static_cast<int32_t>(sglGameSeed));
+	const int32_t seed = static_cast<int32_t>(sglGameSeed);
+	return seed == -2147483648 ? -2147483648 : abs(seed);
 }
 
 int32_t AdvanceRndSeed()
