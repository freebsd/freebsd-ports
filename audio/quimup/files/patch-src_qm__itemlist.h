--- src/qm_itemlist.h.orig	2018-12-09 18:43:06 UTC
+++ src/qm_itemlist.h
@@ -63,7 +63,7 @@ class qm_listitemInfo (public)
     QString sorter;
 
     // Override the < operator for alist.sort();
-    bool operator < (const qm_listitemInfo& litem)
+    bool operator < (const qm_listitemInfo& litem) const
     {
         return sorter < litem.sorter;
     }
