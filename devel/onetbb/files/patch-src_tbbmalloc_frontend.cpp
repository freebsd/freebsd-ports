Backport fa944e19600500863507ed8e9b1f5a30037d9df6

--- src/tbbmalloc/frontend.cpp.orig	2021-06-30 08:19:55 UTC
+++ src/tbbmalloc/frontend.cpp
@@ -802,21 +802,15 @@ static inline unsigned int highestBitPos(unsigned int 
     return pos;
 }
 
-
-#if __TBB_x86_32 || __aarch32__
 unsigned int getSmallObjectIndex(unsigned int size)
 {
-    return (size-1)>>3;
-}
-#elif __TBB_x86_64 || __aarch64__
-unsigned int getSmallObjectIndex(unsigned int size)
-{
-    // For 64-bit malloc, 16 byte alignment is needed except for bin 0.
     unsigned int result = (size-1)>>3;
-    if (result) result |= 1; // 0,1,3,5,7; bins 2,4,6 are not aligned to 16 bytes
+    if (sizeof(void*)==8) {
+        // For 64-bit malloc, 16 byte alignment is needed except for bin 0.
+        if (result) result |= 1; // 0,1,3,5,7; bins 2,4,6 are not aligned to 16 bytes
+    }
     return result;
 }
-#endif // __TBB_x86_32 ||  __aarch32__
 
 /*
  * Depending on indexRequest, for a given size return either the index into the bin
