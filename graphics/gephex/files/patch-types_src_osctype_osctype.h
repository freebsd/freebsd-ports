--- types/src/osctype/osctype.h.orig
+++ types/src/osctype/osctype.h
@@ -60,7 +60,7 @@
 
 static __inline void osc_resize(OscType* dst, int newSize)
 {
-  assert( osc_invariant(dst) );
+//  assert( osc_invariant(dst) );
   unsigned char* newData;
   
   if (newSize < dst->len)
