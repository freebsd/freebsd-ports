--- src/core/matrix.cpp.orig	2020-10-16 23:15:05 UTC
+++ src/core/matrix.cpp
@@ -2236,7 +2236,7 @@ bool    _Matrix::IncreaseStorage    (void) {
         } else {
             theData = (hyFloat*) MemReallocate(theData, lDim*sizeof(void*));
             for (long i = lDim-allocationBlock; i < lDim; i++) {
-                theData [i] = ZEROPOINTER;
+                theData [i] = ZEROOBJECT;
             }
         }
     } else {
