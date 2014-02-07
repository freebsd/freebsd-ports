--- engine/calculators/PieCalculator.cpp.orig
+++ engine/calculators/PieCalculator.cpp
@@ -147,7 +147,7 @@
 
   // erase the smallest accounts
   Money other;
-  std::map<Money,int>::iterator it = smap.begin();
+  auto it = smap.begin();
   while( mergenum >= 0  ){
     other += it->first;
 
