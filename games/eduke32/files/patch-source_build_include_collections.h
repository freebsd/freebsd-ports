--- source/build/include/collections.h.orig	2018-02-19 14:35:27 UTC
+++ source/build/include/collections.h
@@ -41,7 +41,7 @@ struct GrowArray
     void vacuum()
     {
         if (size_ < capacity_)
-            reallocate(size);
+            reallocate(size());
     }
 
     void clear()
