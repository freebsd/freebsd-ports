--- base/containers/id_map.h.orig	2024-06-13 07:40:39 UTC
+++ base/containers/id_map.h
@@ -178,8 +178,8 @@ class IDMap final {
     }
 
     const Iterator& operator=(const Iterator& iter) {
-      map_ = iter.map;
-      iter_ = iter.iter;
+      map_ = iter.map_;
+      iter_ = iter.iter_;
       Init();
       return *this;
     }
