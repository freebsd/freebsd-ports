--- src/anneal.h.orig	Sun Nov 21 18:23:08 2004
+++ src/anneal.h	Mon May  7 21:21:12 2007
@@ -678,7 +678,7 @@
 
             localK = stateSpace->size();
             if (localK < 2) convergedPoints[index] = true;
-            kMax = std::max(kMax, stateProbabilities->size());
+            kMax = std::max((size_t)kMax, stateProbabilities->size());
 
         }
 
