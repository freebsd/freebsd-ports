--- src/LocationList.h.orig	2010-05-11 08:50:34.000000000 +0000
+++ src/LocationList.h
@@ -55,7 +55,7 @@ template<class T> class LocationList : p
 
   void add(T t)
     {
-      push_back(t);
+      this->push_back(t);
       d_id[t->getId()] = t;
       int size = t->getSize();
       for (int i = 0; i < size; i++)
