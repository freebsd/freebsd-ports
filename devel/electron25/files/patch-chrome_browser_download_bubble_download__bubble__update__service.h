--- chrome/browser/download/bubble/download_bubble_update_service.h.orig	2023-05-25 00:41:42 UTC
+++ chrome/browser/download/bubble/download_bubble_update_service.h
@@ -208,8 +208,8 @@ class DownloadBubbleUpdateService
 
   // Removes item if we already have the iterator to it. Returns next iterator.
   template <typename Id, typename Item>
-  SortedItems<Item>::iterator RemoveItemFromCacheByIter(
-      SortedItems<Item>::iterator iter,
+  typename SortedItems<Item>::iterator RemoveItemFromCacheByIter(
+      typename SortedItems<Item>::iterator iter,
       SortedItems<Item>& cache,
       IterMap<Id, Item>& iter_map);
 
