--- include/ptlib/array.h.orig	2011-06-23 00:28:13.000000000 +0200
+++ include/ptlib/array.h	2011-06-23 00:28:34.000000000 +0200
@@ -644,7 +644,7 @@
       T t;
       stream >> t;
       if (!stream.fail())
-        SetAt(index, t);
+        this->SetAt(index, t);
     }
 };
 
