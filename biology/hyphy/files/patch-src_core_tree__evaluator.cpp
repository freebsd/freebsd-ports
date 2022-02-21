--- src/core/tree_evaluator.cpp.orig	2022-02-21 19:48:41 UTC
+++ src/core/tree_evaluator.cpp
@@ -127,7 +127,6 @@ inline double _sse_sum_2 (__m128d const & x) {
 template<long D> inline void __ll_handle_matrix_transpose (hyFloat const * __restrict transitionMatrix, hyFloat * __restrict tMatrixT) {
     long i = 0L;
     for (long r = 0L; r < D; r++) {
-        #pragma unroll(4)
         #pragma GCC unroll 4
         for (long c = 0L; c < D; c++, i++) {
             tMatrixT[c*D+r] = transitionMatrix[i];
@@ -154,7 +153,6 @@ template<long D> inline bool __ll_handle_conditional_a
                 }
             }*/
             
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long k = 0L; k < D; k++) {
                 parentConditionals[k] *= tMatrix[siteState+D*k];
@@ -172,7 +170,6 @@ template<long D> inline bool __ll_handle_conditional_a
     } else {
         if (tcc) {
             if (__builtin_expect((tcc->list_data[currentTCCIndex] & bitMaskArray.masks[currentTCCBit]) > 0 && siteID > siteFrom,0)) {
-                #pragma unroll(4)
                 #pragma GCC unroll 4
                 for (long k = 0L; k < D; k++) {
                     childVector[k] = lastUpdatedSite[k];
@@ -200,7 +197,6 @@ inline bool __ll_handle_conditional_array_initializati
         }
         if (__builtin_expect(siteState >= 0L,1)) {
             // a single character state; sweep down the appropriate column
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long k = 0L; k < D; k++) {
                 parentConditionals[k] *= tMatrix[siteState+D*k];
@@ -212,7 +208,6 @@ inline bool __ll_handle_conditional_array_initializati
     } else {
         if (tcc) {
             if (__builtin_expect((tcc->list_data[currentTCCIndex] & bitMaskArray.masks[currentTCCBit]) > 0 && siteID > siteFrom,0)) {
-                #pragma unroll(4)
                 #pragma GCC unroll 4
                 for (long k = 0L; k < D; k++) {
                     childVector[k] = lastUpdatedSite[k];
@@ -542,7 +537,6 @@ template<long D> inline void __ll_product_sum_loop (hy
         #pragma GCC unroll 8
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         for (long c = 0; c < D; c++)
             accumulator +=  tMatrix[c]   * childVector[c];
         
@@ -558,7 +552,6 @@ inline void __ll_product_sum_loop_generic (hyFloat con
         #pragma GCC unroll 8
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         for (long c = 0; c < D; c++)
             accumulator +=  tMatrix[c]   * childVector[c];
         
@@ -595,7 +588,6 @@ template<long D, bool ADJUST> inline void __ll_loop_ha
             fprintf (stderr, "UP %ld (%ld) %lg\n", didScale, parentCode, scaler);
         }*/
         if (didScale) {
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long c = 0; c < D; c++) {
                 parentConditionals [c] *= scaler;
@@ -626,7 +618,6 @@ template<long D, bool ADJUST> inline void __ll_loop_ha
                 }*/
                 
                 if (didScale) {
-                    #pragma unroll(4)
                     #pragma GCC unroll 4
                     for (long c = 0; c < D; c++) {
                         parentConditionals [c] *= scaler;
@@ -657,7 +648,6 @@ template<bool ADJUST> inline void __ll_loop_handle_sca
         hyFloat scaler = _computeBoostScaler(scalingAdjustments [parentCode*siteCount + siteID] * _lfScalerUpwards, sum, didScale);
         
         if (didScale) {
-            #pragma unroll(8)
             #pragma GCC unroll 8
             for (long c = 0; c < D; c++) {
                 parentConditionals [c] *= scaler;
@@ -679,7 +669,6 @@ template<bool ADJUST> inline void __ll_loop_handle_sca
                 hyFloat scaler = _computeReductionScaler (scalingAdjustments [parentCode*siteCount + siteID] * _lfScalingFactorThreshold, sum, didScale);
                 
                 if (didScale) {
-                    #pragma unroll(8)
                     #pragma GCC unroll 8
                     for (long c = 0; c < D; c++) {
                          parentConditionals [c] *= scaler;
@@ -707,7 +696,6 @@ template<long D> inline void __ll_loop_handle_leaf_cas
     } else {
         for (long k = siteFrom; k < siteTo; k++, pp += D) {
             hyFloat lsf = localScalingFactor[k];
-#pragma unroll(4)
 #pragma GCC unroll 4
             for (long s = 0; s < D; s++) {
                 pp[s] = lsf;
@@ -1585,7 +1573,6 @@ hyFloat      _TheTree::ComputeTreeBlockByBranch  (    
             accumulator         = rootConditionals[rootIndex + rootState] * theProbs[rootState];
             rootIndex           += alphabetDimension;
         } else {
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long p = 0; p < alphabetDimension; p++,rootIndex++) {
                 accumulator += rootConditionals[rootIndex] * theProbs[p];
@@ -1644,7 +1631,6 @@ template<long D> inline bool __lcache_loop_preface (bo
         long siteState = lNodeFlags[nodeCode*siteCount + siteOrdering.list_data[siteID]] ;
         if (siteState >= 0L) {
             unsigned long target_index = siteState;
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long k = 0L; k < D; k++, target_index+=D) {
                 parentConditionals[k]   *= tMatrix[target_index];
@@ -1659,7 +1645,6 @@ template<long D> inline bool __lcache_loop_preface (bo
             if ((tcc->list_data[currentTCCIndex] & bitMaskArray.masks[currentTCCBit]) > 0 && siteID > siteFrom)
                 // the value of this conditional vector needs to be copied from a previously stored site
                 // subtree duplication
-                #pragma unroll(4)
                 #pragma GCC unroll 4
                 for (long k = 0UL; k < D; k++) {
                     childVector[k] = lastUpdatedSite[k];
@@ -1688,7 +1673,6 @@ inline bool __lcache_loop_preface_generic (bool isLeaf
         long siteState = lNodeFlags[nodeCode*siteCount + siteOrdering.list_data[siteID]] ;
         if (siteState >= 0L) {
             unsigned long target_index = siteState;
-            #pragma unroll(4)
             #pragma GCC unroll 4
             for (long k = 0L; k < D; k++, target_index+=D) {
                 parentConditionals[k]   *= tMatrix[target_index];
@@ -1704,7 +1688,6 @@ inline bool __lcache_loop_preface_generic (bool isLeaf
             if ((tcc->list_data[currentTCCIndex] & bitMaskArray.masks[currentTCCBit]) > 0 && siteID > siteFrom)
                 // the value of this conditional vector needs to be copied from a previously stored site
                 // subtree duplication
-                #pragma unroll(4)
                 #pragma GCC unroll 4
                 for (long k = 0UL; k < D; k++) {
                     childVector[k] = lastUpdatedSite[k];
@@ -1966,7 +1949,6 @@ void            _TheTree::ComputeBranchCache    (
                 unsigned long k3     = 0UL;
                 for (unsigned long k = siteFrom; k < siteTo; k++) {
                     hyFloat scaler = localScalingFactor[k];
-                    #pragma unroll(4)
                     #pragma GCC unroll 4
                     for (unsigned long k2 = 0UL; k2 < alphabetDimension; k2++, k3++) {
                         parentConditionals [k3] = scaler;
@@ -2474,7 +2456,6 @@ void            _TheTree::ComputeBranchCache    (
                     #pragma GCC unroll 8
                     #pragma clang loop vectorize(enable)
                     #pragma clang loop interleave(enable)
-                    #pragma clang loop unroll(enable)
                     for (long k = 0; k < alphabetDimension; k++) {
                         sum += parentConditionals[k];
                     }
