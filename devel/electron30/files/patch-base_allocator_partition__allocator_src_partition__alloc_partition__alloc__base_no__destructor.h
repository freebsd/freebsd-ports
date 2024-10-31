--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/no_destructor.h.orig	2024-06-13 07:40:39 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/no_destructor.h
@@ -122,9 +122,7 @@ class NoDestructor {
       new (storage_) T(std::forward<Args>(args)...);
     }
 
-    const T* get() const {
-      return const_cast<PlacementStorage*>(this)->storage();
-    }
+    const T* get() const { return const_cast<PlacementStorage*>(this)->get(); }
     T* get() { return reinterpret_cast<T*>(storage_); }
 
    private:
