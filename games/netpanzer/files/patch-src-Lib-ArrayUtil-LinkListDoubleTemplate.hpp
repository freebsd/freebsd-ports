--- src/Lib/ArrayUtil/LinkListDoubleTemplate.hpp.orig	Tue Dec  2 12:40:14 2003
+++ src/Lib/ArrayUtil/LinkListDoubleTemplate.hpp	Thu Aug 19 16:34:25 2004
@@ -203,7 +203,7 @@
             object->prev->next = before;
         }
 
-        if(delete_ptr == front) {
+        if(object == front) {
             front = before;
         }
 
