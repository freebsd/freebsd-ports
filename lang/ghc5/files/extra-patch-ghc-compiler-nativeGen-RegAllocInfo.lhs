--- ghc/compiler/nativeGen/RegAllocInfo.lhs.orig	Tue Jan 29 17:52:32 2002
+++ ghc/compiler/nativeGen/RegAllocInfo.lhs	Thu Dec 11 13:30:50 2003
@@ -808,9 +808,9 @@
 
 	{-I386: spill above stack pointer leaving 3 words/spill-}
 	,IF_ARCH_i386 ( let off_w = (off-delta) `div` 4
-                        in case regClass vreg of
-                              RcInteger -> MOV L (OpReg dyn) (OpAddr (spRel off_w))
-                              _         -> GST F80 dyn (spRel off_w) -- RcFloat/RcDouble
+                        in case regClass vreg of {
+                              RcInteger -> MOV L (OpReg dyn) (OpAddr (spRel off_w));
+                              _         -> GST F80 dyn (spRel off_w)} -- RcFloat/RcDouble
 
 	{-SPARC: spill below frame pointer leaving 2 words/spill-}
 	,IF_ARCH_sparc( 
@@ -831,9 +831,9 @@
 	 IF_ARCH_alpha( LD  sz dyn (spRel (- (off `div` 8)))
 
 	,IF_ARCH_i386 ( let off_w = (off-delta) `div` 4
-                        in case regClass vreg of
-                              RcInteger -> MOV L (OpAddr (spRel off_w)) (OpReg dyn)
-                              _         -> GLD F80 (spRel off_w) dyn -- RcFloat/RcDouble
+                        in case regClass vreg of {
+                              RcInteger -> MOV L (OpAddr (spRel off_w)) (OpReg dyn);
+                              _         -> GLD F80 (spRel off_w) dyn} -- RcFloat/RcDouble
 
 	,IF_ARCH_sparc( 
                         let off_w = 1 + (off `div` 4)
