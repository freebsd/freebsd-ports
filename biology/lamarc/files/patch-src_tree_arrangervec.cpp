--- src/tree/arrangervec.cpp.orig	2025-05-18 23:55:20 UTC
+++ src/tree/arrangervec.cpp
@@ -116,7 +116,7 @@ void ArrangerVec::CopyAllMembers(const ArrangerVec & c
         for(it = cp.arrangers.begin(); it != cp.arrangers.end(); it++)
         {
             Arranger* arr = (*it).second->Clone();
-            arrangers.insert(std::make_pair<string, Arranger*>(arr->GetName(), arr));
+            arrangers.insert(std::make_pair(arr->GetName(), arr));
         }
     }
 }
