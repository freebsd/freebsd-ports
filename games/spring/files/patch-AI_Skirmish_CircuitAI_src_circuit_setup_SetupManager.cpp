--- AI/Skirmish/CircuitAI/src/circuit/setup/SetupManager.cpp.orig	2021-01-01 16:10:55 UTC
+++ AI/Skirmish/CircuitAI/src/circuit/setup/SetupManager.cpp
@@ -26,6 +26,8 @@
 #include "Info.h"
 
 #include <regex>
+#include <algorithm>
+#include <random>
 
 namespace circuit {
 
@@ -183,7 +185,9 @@ void CSetupManager::PickStartPos(CCircuitAI* circuit, 
 					c.distDivIncome = center.distance(cl.position) / income;
 					validClusters.push_back(std::make_pair(kv.first, c));
 				}
-				std::random_shuffle(validClusters.begin(), validClusters.end());
+				std::random_device rd;
+				std::minstd_rand g(rd());
+				std::shuffle(validClusters.begin(), validClusters.end(), g);
 
 				auto cmp = [](const std::pair<int, SCluster>& a, const std::pair<int, SCluster>& b) {
 					if (a.second.count < b.second.count) {
