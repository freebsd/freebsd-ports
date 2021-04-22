--- rts/Sim/Projectiles/ProjectileHandler.cpp.orig	2020-12-26 12:45:43 UTC
+++ rts/Sim/Projectiles/ProjectileHandler.cpp
@@ -66,6 +66,18 @@ ProjMemPool projMemPool;
 CProjectileHandler projectileHandler;
 
 
+namespace {
+	template<class RandomIt, class RandomFunc>
+	void random_shuffle(RandomIt first, RandomIt last, RandomFunc&& r)
+	{
+		typename std::iterator_traits<RandomIt>::difference_type i, n;
+		n = last - first;
+		for (i = n-1; i > 0; --i) {
+			using std::swap;
+			swap(first[i], first[r(i+1)]);
+		}
+	}
+}
 
 void CProjectileHandler::Init()
 {
@@ -106,8 +118,8 @@ void CProjectileHandler::Init()
 			freeProjectileIDs[false].push_back(i);
 		}
 
-		std::random_shuffle(freeProjectileIDs[ true].begin(), freeProjectileIDs[ true].end(), gsRNG);
-		std::random_shuffle(freeProjectileIDs[false].begin(), freeProjectileIDs[false].end(), guRNG);
+		::random_shuffle(freeProjectileIDs[ true].begin(), freeProjectileIDs[ true].end(), gsRNG);
+		::random_shuffle(freeProjectileIDs[false].begin(), freeProjectileIDs[false].end(), guRNG);
 	}
 
 	for (int modelType = 0; modelType < MODELTYPE_OTHER; ++modelType) {
@@ -395,7 +407,7 @@ void CProjectileHandler::AddProjectile(CProjectile* p)
 
 			// generate (newSize - oldSize) new id's starting from oldSize
 			std::for_each(freeIDs.begin(), freeIDs.end(), [k = oldSize](int& id) mutable { id = k++; });
-			std::random_shuffle(freeIDs.begin(), freeIDs.end(), rngFunc);
+			::random_shuffle(freeIDs.begin(), freeIDs.end(), rngFunc);
 		}
 
 
