--- src/qm_itemlist.h.orig
+++ src/qm_itemlist.h
@@ -63,7 +63,7 @@
     QString sorter;
 
     // Override the < operator for alist.sort();
-    bool operator < (const qm_listitemInfo& litem)
+    bool operator < (const qm_listitemInfo& litem) const
     {
         return sorter < litem.sorter;
     }
