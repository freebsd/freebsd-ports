--- hv.c.orig	2020-12-18 10:04:36 UTC
+++ hv.c
@@ -2185,30 +2185,31 @@ PERL_STATIC_INLINE U32 S_ptr_hash(PTRV u) {
  */
 
 PERL_STATIC_INLINE U32 S_ptr_hash(PTRV u) {
+    UVINT h = u;
 #if PTRSIZE == 8
     /*
      * This is one of Thomas Wang's hash functions for 64-bit integers from:
      * http://www.concentric.net/~Ttwang/tech/inthash.htm
      */
-    u = (~u) + (u << 18);
-    u = u ^ (u >> 31);
-    u = u * 21;
-    u = u ^ (u >> 11);
-    u = u + (u << 6);
-    u = u ^ (u >> 22);
+    h = (~h) + (h << 18);
+    h = h ^ (h >> 31);
+    h = h * 21;
+    h = h ^ (h >> 11);
+    h = h + (h << 6);
+    h = h ^ (h >> 22);
 #else
     /*
      * This is one of Bob Jenkins' hash functions for 32-bit integers
      * from: http://burtleburtle.net/bob/hash/integer.html
      */
-    u = (u + 0x7ed55d16) + (u << 12);
-    u = (u ^ 0xc761c23c) ^ (u >> 19);
-    u = (u + 0x165667b1) + (u << 5);
-    u = (u + 0xd3a2646c) ^ (u << 9);
-    u = (u + 0xfd7046c5) + (u << 3);
-    u = (u ^ 0xb55a4f09) ^ (u >> 16);
+    h = (h + 0x7ed55d16) + (h << 12);
+    h = (h ^ 0xc761c23c) ^ (h >> 19);
+    h = (h + 0x165667b1) + (h << 5);
+    h = (h + 0xd3a2646c) ^ (h << 9);
+    h = (h + 0xfd7046c5) + (h << 3);
+    h = (h ^ 0xb55a4f09) ^ (h >> 16);
 #endif
-    return (U32)u;
+    return (U32)h;
 }
 
 static struct xpvhv_aux*
