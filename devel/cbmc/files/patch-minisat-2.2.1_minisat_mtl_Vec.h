--- minisat-2.2.1/minisat/mtl/Vec.h.orig	2011-02-21 13:31:17 UTC
+++ minisat-2.2.1/minisat/mtl/Vec.h
@@ -96,9 +96,11 @@ void vec<T>::capacity(int min_cap) {
 void vec<T>::capacity(int min_cap) {
     if (cap >= min_cap) return;
     int add = imax((min_cap - cap + 1) & ~1, ((cap >> 1) + 2) & ~1);   // NOTE: grow by approximately 3/2
-    if (add > INT_MAX - cap || ((data = (T*)::realloc(data, (cap += add) * sizeof(T))) == NULL) && errno == ENOMEM)
+    if (add > INT_MAX - cap)
         throw OutOfMemoryException();
- }
+
+    data = (T*)xrealloc(data, (cap += add) * sizeof(T));
+}
 
 
 template<class T>
