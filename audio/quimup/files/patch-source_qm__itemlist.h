--- source/qm_itemlist.h.orig	2024-01-30 12:25:50 UTC
+++ source/qm_itemlist.h
@@ -49,7 +49,7 @@ class qm_listItemInfo (public)
     QString sorter;
 
     // Override the < operator for alist.sort();
-    bool operator < (const qm_listItemInfo& litem)
+    bool operator < (const qm_listItemInfo& litem) const
     {
         return sorter < litem.sorter;
     }
