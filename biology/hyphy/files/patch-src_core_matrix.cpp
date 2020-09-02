--- src/core/matrix.cpp.orig	2020-09-02 16:12:43 UTC
+++ src/core/matrix.cpp
@@ -3128,8 +3128,6 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
                      CELL_OP (idx+8);
                      CELL_OP (idx+12);
                  }
-            }
-
  #else
                 for (long idx = 0; idx < upto; idx+=4) {
                     stData[idx]+=argData[idx];
@@ -3138,7 +3136,7 @@ void    _Matrix::AddMatrix  (_Matrix& storage, _Matrix
                     stData[idx+3]+=argData[idx+3];
                 }
 #endif
-                
+            }
             if (subtract)
                 for (long idx = upto; idx < secondArg.lDim; idx++) {
                     stData[idx]-=argData[idx];
