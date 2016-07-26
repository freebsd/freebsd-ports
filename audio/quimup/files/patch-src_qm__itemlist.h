--- src/qm_itemlist.h.orig	2016-02-28 09:52:29 UTC
+++ src/qm_itemlist.h
@@ -63,7 +63,7 @@ public:
     QString sorter;
 
     // Override the < operator for alist.sort();
-    bool operator < (const qm_listitemInfo& litem)
+    bool operator < (const qm_listitemInfo& litem) const
     {
         return sorter < litem.sorter;
     }
