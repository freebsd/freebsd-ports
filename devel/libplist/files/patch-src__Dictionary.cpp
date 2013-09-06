--- ./src/Dictionary.cpp.orig	2013-03-19 17:34:11.000000000 +0100
+++ ./src/Dictionary.cpp	2013-09-06 21:56:58.185535926 +0200
@@ -151,7 +151,7 @@
         _map[key] = clone;
         return _map.find(key);
     }
-    return iterator(NULL);
+    return iterator();
 }
 
 void Dictionary::Remove(Node* node)
