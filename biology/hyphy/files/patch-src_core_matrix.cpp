--- src/core/matrix.cpp.orig	2022-04-24 18:04:11 UTC
+++ src/core/matrix.cpp
@@ -3405,7 +3405,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
         #pragma GCC unroll 4
         #pragma clang loop vectorize(enable)
         #pragma clang loop interleave(enable)
-        #pragma clang loop unroll(enable)
         #pragma GCC ivdep
         #pragma ivdep
                for (long idx = 0; idx < upto; idx+=16) {
@@ -3909,7 +3908,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                  #pragma GCC unroll 4
                                  #pragma clang loop vectorize(enable)
                                  #pragma clang loop interleave(enable)
-                                 #pragma clang loop unroll(enable)
                                  for (long k = 0; k < vDim; k+=4) {
                                       __m256d D4, B4;
                                       DO_GROUP_OP (D4, B4, k);
@@ -3960,7 +3958,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                   #pragma GCC unroll 4
                                   #pragma clang loop vectorize(enable)
                                   #pragma clang loop interleave(enable)
-                                  #pragma clang loop unroll(enable)
                                   for (long k = 0; k < vDim; k+=2) {
                                       __m128d D4, B4;
                                       DO_GROUP_OP1 (D4, B4, k);
@@ -4177,7 +4174,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                             #pragma GCC unroll 4
                             #pragma clang loop vectorize(enable)
                             #pragma clang loop interleave(enable)
-                            #pragma clang loop unroll(enable)
                               for (long k = 0; k < dimm4; k+=4) {
                                   __m256d D4, B4;
                                   DO_GROUP_OP (D4, B4, k);
@@ -4285,7 +4281,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                                         #pragma GCC unroll 4
                                         #pragma clang loop vectorize(enable)
                                         #pragma clang loop interleave(enable)
-                                        #pragma clang loop unroll(enable)
                                         for (long k = 0; k < dimm4; k+=2) {
                                             __m128d D4, B4;
                                             DO_GROUP_OP1 (D4, B4, k);
@@ -4455,7 +4450,6 @@ void    _Matrix::Multiply  (_Matrix& storage, _Matrix 
                         #pragma GCC unroll 8
                         #pragma clang loop vectorize(enable)
                         #pragma clang loop interleave(enable)
-                        #pragma clang loop unroll(enable)
                         for (long k = 0, column = j*hDim; k < vDim; k++, column ++) {
                             resCell += row[k] * secondArg.theData [column];
                         }
