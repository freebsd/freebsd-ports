--- src/buildstardb.cpp.orig	Sat Aug 30 21:33:27 2003
+++ src/buildstardb.cpp	Sat Aug 30 21:34:05 2003
@@ -921,7 +921,7 @@
             {
                 MultistarSystem* multiSystem = new MultistarSystem();
                 multiSystem->nStars = 1;
-                multiSystem->stars[0] = iter;
+                multiSystem->stars[0] = &(*iter);
                 starSystems.insert(MultistarSystemCatalog::value_type(iter->CCDMIdentifier, multiSystem));
             }
             else
@@ -933,7 +933,7 @@
                 }
                 else
                 {
-                    multiSystem->stars[multiSystem->nStars] = iter;
+                    multiSystem->stars[multiSystem->nStars] = &(*iter);
                     multiSystem->nStars++;
                 }
             }
@@ -1162,7 +1162,7 @@
         for (vector<HipparcosStar>::iterator iter = stars.begin();
              iter != stars.end(); iter++)
         {
-            starIndex.insert(starIndex.end(), iter);
+            starIndex.insert(starIndex.end(), &(*iter));
         }
 
         HIPCatalogComparePredicate pred;
