--- src/Lib/ArrayUtil/QueueTemplate.hpp.orig	Sun Dec 21 01:48:03 2003
+++ src/Lib/ArrayUtil/QueueTemplate.hpp	Thu Aug 19 16:34:31 2004
@@ -42,8 +42,8 @@
 
     bool enqueue(const TYPE& object )
     {
-        add( object, (rear + 1) % size );
-        rear = (rear + 1) % size;
+        add( object, (rear + 1) % this->size );
+        rear = (rear + 1) % this->size;
 
         if ( front == rear )
             return( false );
@@ -55,29 +55,29 @@
     {
         assert( front != rear );
 
-        front = ( front + 1 ) % size;
-        return( array[ front ] );
+        front = ( front + 1 ) % this->size;
+        return( this->array[ front ] );
     }
 
     void pop()
     {
         assert( front != rear );
 
-        front = ( front + 1 ) % size;
+        front = ( front + 1 ) % this->size;
     }
 
     TYPE getFirst()
     {
         assert( front != rear );
 
-        return( array[ (( front + 1 ) % size) ] );
+        return( this->array[ (( front + 1 ) % this->size) ] );
     }
 
     TYPE * getFirstPtr()
     {
         assert( front != rear );
 
-        return( &(array[ (( front + 1 ) % size) ]) );
+        return( &(this->array[ (( front + 1 ) % this->size) ]) );
     }
 
 
@@ -88,7 +88,7 @@
 
     bool isFull () const
     {
-        return front == (rear + 1) % size;
+        return front == (rear + 1) % this->size;
     }
 
     bool isReady() const
@@ -99,7 +99,7 @@
     unsigned long itemCount() const
     {
         if ( front > rear )
-            return ( (rear+1) + ( (size-1) - front ) );
+            return ( (rear+1) + ( (this->size-1) - front ) );
         else
             return ( rear - front );
     }
