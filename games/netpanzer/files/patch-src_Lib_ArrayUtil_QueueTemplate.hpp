--- src/Lib/ArrayUtil/QueueTemplate.hpp.orig	2012-04-24 23:51:05.000000000 +0200
+++ src/Lib/ArrayUtil/QueueTemplate.hpp	2012-04-24 23:51:15.000000000 +0200
@@ -42,7 +42,7 @@
 
     bool enqueue(const TYPE& object )
     {
-        add( object, (rear + 1) % this->size );
+        this->add( object, (rear + 1) % this->size );
         rear = (rear + 1) % this->size;
 
         if ( front == rear )
