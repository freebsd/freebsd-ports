--- tree/tree.cc.orig	2026-06-16 01:26:05 UTC
+++ tree/tree.cc
@@ -115,7 +115,7 @@ class CachedTypeCheck {
     auto* type = Py_TYPE(o);
 
     {
-      absl::MutexLock lock(mutex_);
+      absl::MutexLock lock(&mutex_);
       auto it = type_to_sequence_map_.find(type);
       if (it != type_to_sequence_map_.end()) {
         return it->second;
@@ -135,7 +135,7 @@ class CachedTypeCheck {
     // that are eligible for decref. As a precaution, we limit the size of the
     // map to 1024.
     {
-      absl::MutexLock lock(mutex_);
+      absl::MutexLock lock(&mutex_);
       if (type_to_sequence_map_.size() < kMaxItemsInCache) {
         Py_INCREF(type);
         type_to_sequence_map_.insert({type, check_result});
