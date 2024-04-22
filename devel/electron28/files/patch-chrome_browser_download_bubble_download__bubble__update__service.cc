--- chrome/browser/download/bubble/download_bubble_update_service.cc.orig	2023-11-29 21:39:47 UTC
+++ chrome/browser/download/bubble/download_bubble_update_service.cc
@@ -89,7 +89,11 @@ template <typename Item>
 // Helper to get an iterator to the last element in the cache. The cache
 // must not be empty.
 template <typename Item>
+#if defined(__clang__) && (__clang_major__ >= 16)
 SortedItems<Item>::const_iterator GetLastIter(const SortedItems<Item>& cache) {
+#else
+typename SortedItems<Item>::const_iterator GetLastIter(const SortedItems<Item>& cache) {
+#endif
   CHECK(!cache.empty());
   auto it = cache.end();
   return std::prev(it);
@@ -1089,9 +1093,17 @@ template <typename Id, typename Item>
 }
 
 template <typename Id, typename Item>
+#if defined(__clang__) && (__clang_major__ >= 16)
 SortedItems<Item>::iterator
+#else
+typename SortedItems<Item>::iterator
+#endif
 DownloadBubbleUpdateService::CacheManager::RemoveItemFromCacheByIter(
+#if defined(__clang__) && (__clang_major__ >= 16)
     SortedItems<Item>::iterator iter,
+#else
+    typename SortedItems<Item>::iterator iter,
+#endif
     SortedItems<Item>& cache,
     IterMap<Id, Item>& iter_map) {
   CHECK(iter != cache.end());
