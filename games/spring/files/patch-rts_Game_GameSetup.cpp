--- rts/Game/GameSetup.cpp.orig	2021-01-01 16:12:22 UTC
+++ rts/Game/GameSetup.cpp
@@ -255,7 +255,7 @@ void CGameSetup::LoadStartPositions(bool withoutMap)
 		// Server syncs these later, so we can use unsynced rng
 		CGlobalUnsyncedRNG rng;
 		rng.Seed(HsiehHash(setupText.c_str(), setupText.length(), 1234567));
-		std::random_shuffle(teamStartNums.begin(), teamStartNums.begin() + teamStartingData.size(), rng);
+		std::shuffle(teamStartNums.begin(), teamStartNums.begin() + teamStartingData.size(), rng);
 	}
 
 	for (size_t i = 0; i < teamStartingData.size(); ++i)
