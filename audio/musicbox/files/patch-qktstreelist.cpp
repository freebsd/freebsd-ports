--- qktstreelist.cpp.orig	Mon Nov 10 18:10:02 1997
+++ qktstreelist.cpp	Wed Jun  9 00:15:13 1999
@@ -834,7 +834,7 @@
   QktsItemSearchInfo searchInfo;
   searchInfo.index = index;
   searchInfo.count = -1;
-  forEveryVisibleItem(QktsTreeList::findItemAt, &searchInfo);
+  forEveryVisibleItem(&QktsTreeList::findItemAt, &searchInfo);
   return searchInfo.foundItem;
 }
 
@@ -1340,7 +1340,7 @@
   QktsTreeListItem *item = treeRoot->getChild();
   do {
     while(item) {
-      if((func)(item, user)) return;
+      if((this->*func)(item, user)) return;
       if(item->hasChild() && item->isExpanded()) {
         stack.push(item);
         item = item->getChild();
