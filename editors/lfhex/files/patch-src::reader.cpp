
$FreeBSD$

--- src/reader.cpp.orig
+++ src/reader.cpp
@@ -12,6 +12,7 @@
 #include <stdexcept>
 #include <algorithm>
 #include <new>
+#include <cassert>
 
 // for stat:
 #include <sys/types.h>
@@ -117,7 +118,7 @@
   return true;
 }
 
-INLINE bool Reader::is_open() const
+bool Reader::is_open() const
 {
   return _is_open;
 }
@@ -195,14 +196,14 @@
   return _offset;
 }
 
-INLINE off_t Reader::tell() const
+off_t Reader::tell() const
 {
   if(!is_open())
     return -1;
   return _offset;
 }
 
-INLINE off_t Reader::size() const
+off_t Reader::size() const
 {
   return _size;
 }
@@ -231,7 +232,7 @@
     // free the page which is the furthest away from the page we are loading
 
     // this could be trouble if off_t is unsigned!
-    if( abs(_firstPage - pageIdx) > abs(_lastPage - pageIdx) ) 
+    if( abs((long int)(_firstPage - pageIdx)) > abs((long int)(_lastPage - pageIdx)) ) 
       while(!freePage(_firstPage++));
     else
       while(!freePage(_lastPage--));
