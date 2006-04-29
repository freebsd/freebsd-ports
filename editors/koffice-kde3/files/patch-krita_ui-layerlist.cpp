--- krita/ui/layerlist.cpp	2006/03/24 09:22:37	522034
+++ krita/ui/layerlist.cpp	2006/04/06 17:18:18	527039
@@ -890,7 +890,7 @@
     QListViewItemIterator it(this);
 
     while (it.current()) {
-        if (it.current() == item) {
+        if (static_cast<const LayerItem *>(it.current()) == item) {
             return true;
         }
         ++it;
