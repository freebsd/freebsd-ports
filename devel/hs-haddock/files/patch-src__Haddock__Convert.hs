--- ./src/Haddock/Convert.hs.orig	2014-04-02 23:25:15.000000000 +0200
+++ ./src/Haddock/Convert.hs	2014-07-14 06:39:49.000000000 +0200
@@ -94,10 +94,10 @@
     (synifyType ImplicitizeForAll (dataConUserType dc)))
 
   AConLike (PatSynCon ps) ->
-      let (_, _, (req_theta, prov_theta)) = patSynSig ps
+      let (_, _, req_theta, prov_theta,_, res_ty) = patSynSig ps
       in SigD $ PatSynSig (synifyName ps)
                           (fmap (synifyType WithinType) (patSynTyDetails ps))
-                          (synifyType WithinType (patSynType ps))
+                          (synifyType WithinType res_ty)
                           (synifyCtx req_theta)
                           (synifyCtx prov_theta)
 
