--- lib/ImageIterator2.hh.orig	2011-03-16 13:35:37.000000000 -0400
+++ lib/ImageIterator2.hh	2011-03-16 13:36:39.000000000 -0400
@@ -358,9 +358,9 @@
     }
     
     accu& abs() {
-      v[0] = std::abs(v[0]);
-      v[1] = std::abs(v[1]);
-      v[2] = std::abs(v[2]);
+      v[0] = std::labs(v[0]);
+      v[1] = std::labs(v[1]);
+      v[2] = std::labs(v[2]);
       return *this;
     }
 
@@ -639,7 +639,7 @@
     }
     
     accu& abs() {
-      v[0] = std::abs(v[0]);
+      v[0] = std::labs(v[0]);
       return *this;
     }
 
