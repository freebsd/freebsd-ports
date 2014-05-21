--- src/LocationList.h.orig	2010-05-11 12:50:34.000000000 +0400
+++ src/LocationList.h	2014-05-21 17:17:08.650652359 +0400
@@ -55,7 +55,7 @@
 
   void add(T t)
     {
-      push_back(t);
+      this->push_back(t);
       d_id[t->getId()] = t;
       int size = t->getSize();
       for (int i = 0; i < size; i++)
@@ -74,8 +74,9 @@
 	for (int j = 0; j < size; j++)
 	  {
 	    Vector<int> pos = t->getPos() + Vector<int>(i,j);
-            if (d_object.find(pos) != d_object.end())
-              d_object.erase(d_object.find(pos));
+            typename PositionMap::const_iterator it = d_object.find(pos);
+            if (it != d_object.end())
+              d_object.erase(it);
 	  }
       delete t;
     }
