--- modules/core/calculation/calculationmanager.cpp.orig	2025-02-15 20:38:45 UTC
+++ modules/core/calculation/calculationmanager.cpp
@@ -111,7 +111,9 @@ void CalculationManager::loadAlgorithms()
 #   endif
 #elif defined(__unix)
     // add system directories on unix systems
-    search_dirs.push_back("/usr/lib/entropypianotuner/algorithms");
+/* FreeBSD change to add LOCALBASE to system directories 
+    search_dirs.push_back("/usr/lib/entropypianotuner/algorithms"); */
+    search_dirs.push_back("%%PREFIX%%/lib/entropypianotuner/algorithms");
     search_dirs.push_back("/usr/lib64/entropypianotuner/algorithms");
     search_dirs.push_back("~/.entropypianotuner/algorithms");
 
