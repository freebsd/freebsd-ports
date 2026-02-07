--- src/control/chainmanager.cpp.orig	2025-05-18 23:57:13 UTC
+++ src/control/chainmanager.cpp
@@ -1631,7 +1631,7 @@ vector<pair<double, long int> > ChainManager::SortChai
     unsigned long int i;
     for (i = 0; i < temps.size(); ++i)
     {
-        orderedtemps.push_back(make_pair<double, long int>(temps[i].GetTemperature(), i));
+        orderedtemps.push_back(make_pair(temps[i].GetTemperature(), i));
     }
     std::sort(orderedtemps.begin(), orderedtemps.end());
     return orderedtemps;
