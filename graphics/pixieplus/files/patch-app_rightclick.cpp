--- app/rightclick.cpp.orig	Sat Sep 18 22:05:03 2004
+++ app/rightclick.cpp	Sat Sep 18 22:05:36 2004
@@ -220,7 +220,7 @@
             idx = -1;
     }
     if(idx != -1){
-        QStringList itemList(view->itemCatagories(&itemList[idx]));
+        QStringList itemList(view->itemCatagories((Thumbnail*)&itemList[idx]));
         for(it=catList.begin(), i=1000; it != catList.end(); ++it, ++i){
             if(itemList.findIndex((*it)) == -1)
                 addMnu->insertItem((*it), i);
