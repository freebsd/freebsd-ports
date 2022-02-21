--- src/core/matrix.cpp.orig	2022-02-21 19:46:34 UTC
+++ src/core/matrix.cpp
@@ -3391,7 +3391,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
         #pragma GCC unroll 4
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         #pragma GCC ivdep
         #pragma ivdep
                for (long idx = 0; idx < upto; idx+=16) {
@@ -3410,7 +3409,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
         #pragma GCC unroll 4
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         #pragma GCC ivdep
         #pragma ivdep
                for (long idx = 0; idx < upto; idx+=8) {
@@ -3440,7 +3438,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
             #pragma GCC unroll 4
             #pragma clang loop vectorize(enable)
             #pragma clang loop interleave(enable)
-            #pragma clang loop unroll(enable)
                  for (long idx = 0; idx < upto; idx+=16) {
                      CELL_OP (idx);
                      CELL_OP (idx+4);
@@ -3454,7 +3451,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
         #pragma GCC unroll 4
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         #pragma GCC ivdep
         #pragma ivdep
                for (long idx = 0; idx < upto; idx+=8) {
@@ -3895,7 +3891,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                  #pragma GCC unroll 4
                                  #pragma clang loop vectorize(enable)
                                  #pragma clang loop interleave(enable)
-                                 #pragma clang loop unroll(enable)
                                  for (long k = 0; k < vDim; k+=4) {
                                       __m256d D4, B4;
                                       DO_GROUP_OP (D4, B4, k);
@@ -3946,7 +3941,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                   #pragma GCC unroll 4
                                   #pragma clang loop vectorize(enable)
                                   #pragma clang loop interleave(enable)
-                                  #pragma clang loop unroll(enable)
                                   for (long k = 0; k < vDim; k+=2) {
                                       __m128d D4, B4;
                                       DO_GROUP_OP1 (D4, B4, k);
@@ -3998,7 +3992,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                             #pragma GCC unroll 4
                             #pragma clang loop vectorize(enable)
                             #pragma clang loop interleave(enable)
-                            #pragma clang loop unroll(enable)
                             for (long k = 0; k < vDim; k+=2) {
                                 float64x2_t D4, B4;
                                 DO_GROUP_OP1 (D4, B4, k);
@@ -4163,7 +4156,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                             #pragma GCC unroll 4
                             #pragma clang loop vectorize(enable)
                             #pragma clang loop interleave(enable)
-                            #pragma clang loop unroll(enable)
                               for (long k = 0; k < dimm4; k+=4) {
                                   __m256d D4, B4;
                                   DO_GROUP_OP (D4, B4, k);
@@ -4271,7 +4263,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                         #pragma GCC unroll 4
                                         #pragma clang loop vectorize(enable)
                                         #pragma clang loop interleave(enable)
-                                        #pragma clang loop unroll(enable)
                                         for (long k = 0; k < dimm4; k+=2) {
                                             __m128d D4, B4;
                                             DO_GROUP_OP1 (D4, B4, k);
@@ -4380,7 +4371,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                   #pragma GCC unroll 4
                                   #pragma clang loop vectorize(enable)
                                   #pragma clang loop interleave(enable)
-                                  #pragma clang loop unroll(enable)
                                   for (long k = 0; k < dimm4; k+=2) {
                                       float64x2_t D4, B4;
                                       DO_GROUP_OP1 (D4, B4, k);
@@ -4441,7 +4431,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                         #pragma GCC unroll 8
                         #pragma clang loop vectorize(enable)
                         #pragma clang loop interleave(enable)
-                        #pragma clang loop unroll(enable)
                         for (long k = 0, column = j*hDim; k < vDim; k++, column ++) {
                             resCell += row[k] * secondArg.theData [column];
                         }
@@ -5822,7 +5811,6 @@ _Matrix*    _Matrix::Exponentiate (hyFloat scale_to, b
                     #pragma GCC unroll 4
                     #pragma clang loop vectorize(enable)
                     #pragma clang loop interleave(enable)
-                    #pragma clang loop unroll(enable)
                     for (long c = from; c < compressedIndex[r]; c++, i++) {
                         theIndex[i] = compressedIndex[c+hDim] * vDim + r;
                     }
@@ -6988,7 +6976,6 @@ hyFloat        _Matrix::Sqr (hyFloat* _hprestrict_ sta
                         #pragma GCC unroll 4
                         #pragma clang loop vectorize(enable)
                         #pragma clang loop interleave(enable)
-                        #pragma clang loop unroll(enable)
                         #pragma GCC ivdep
                         #pragma ivdep
                         for (long k = 0; k < loopBound; k+=4) {
