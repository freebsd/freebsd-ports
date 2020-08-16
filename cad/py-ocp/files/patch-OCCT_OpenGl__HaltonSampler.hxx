--- OCCT/OpenGl_HaltonSampler.hxx.orig	2020-06-15 08:29:45 UTC
+++ OCCT/OpenGl_HaltonSampler.hxx
@@ -180,7 +180,7 @@ void OpenGl_HaltonSampler::initRandom (Random_number_g
     {
       aPerms[aBase][i] = i;
     }
-    std::random_shuffle (aPerms[aBase].begin(), aPerms[aBase].end(), theRand);
+    std::shuffle (aPerms[aBase].begin(), aPerms[aBase].end(), theRand);
   }
   initTables (aPerms);
 }
