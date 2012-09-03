--- include/ptlib/array.h.orig	2012-09-03 22:42:13.000000000 +0200
+++ include/ptlib/array.h	2012-09-03 22:42:49.000000000 +0200
@@ -523,7 +523,7 @@
       T t;
       stream >> t;
       if (!stream.fail())
-        SetAt(index, t);
+        this->SetAt(index, t);
     }
 };
 
