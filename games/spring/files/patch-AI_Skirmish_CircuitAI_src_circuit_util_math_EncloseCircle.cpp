--- ./AI/Skirmish/CircuitAI/src/circuit/util/math/EncloseCircle.cpp.orig	2021-01-01 16:10:55 UTC
+++ ./AI/Skirmish/CircuitAI/src/circuit/util/math/EncloseCircle.cpp
@@ -9,6 +9,7 @@
 #include "util/utils.h"
 
 #include <algorithm>
+#include <random>
 #include <assert.h>
 
 namespace circuit {
@@ -48,7 +49,9 @@ void CEncloseCircle::MakeCircle(const std::vector<AIFl
 		}
 		// Randomize order
 		// TODO: Read why shuffle??
-		std::random_shuffle(shuffled.begin(), shuffled.end());
+		std::random_device rd;
+		std::minstd_rand g(rd());
+		std::shuffle(shuffled.begin(), shuffled.end(), g);
 
 		// Progressively add points to circle or recompute circle
 		decltype(shuffled)::iterator it = shuffled.begin();
