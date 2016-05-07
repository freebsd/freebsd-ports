--- src/MutexImpl.h.orig	2005-03-13 03:59:15 UTC
+++ src/MutexImpl.h
@@ -153,7 +153,7 @@ void MutexImpl<List, Behavior>::acquire(
 
       _owner = self;
 
-      ownerAcquired(self);
+      this->ownerAcquired(self);
       
     }
 
@@ -164,7 +164,7 @@ void MutexImpl<List, Behavior>::acquire(
       _waiters.insert(self);
       m.acquire();
 
-      waiterArrived(self);
+      this->waiterArrived(self);
 
       {        
       
@@ -173,7 +173,7 @@ void MutexImpl<List, Behavior>::acquire(
       
       }
 
-      waiterDeparted(self);
+      this->waiterDeparted(self);
 
       m.release();
         
@@ -192,7 +192,7 @@ void MutexImpl<List, Behavior>::acquire(
           assert(_owner == 0);
           _owner = self;    
 
-          ownerAcquired(self);
+          this->ownerAcquired(self);
 
           break;
         
@@ -236,7 +236,7 @@ bool MutexImpl<List, Behavior>::tryAcqui
 
       _owner = self;
 
-      ownerAcquired(self);
+      this->ownerAcquired(self);
       
     }
 
@@ -253,7 +253,7 @@ bool MutexImpl<List, Behavior>::tryAcqui
       
         m.acquire();
 
-        waiterArrived(self);
+        this->waiterArrived(self);
       
         {
         
@@ -262,7 +262,7 @@ bool MutexImpl<List, Behavior>::tryAcqui
         
         }
 
-        waiterDeparted(self);
+        this->waiterDeparted(self);
       
         m.release();
         
@@ -284,7 +284,7 @@ bool MutexImpl<List, Behavior>::tryAcqui
           assert(0 == _owner);
           _owner = self;
 
-          ownerAcquired(self);
+          this->ownerAcquired(self);
         
           break;
         
@@ -326,7 +326,7 @@ void MutexImpl<List, Behavior>::release(
 
     _owner = 0;
 
-    ownerReleased(impl);
+    this->ownerReleased(impl);
   
     // Try to find a waiter with a backoff & retry scheme
     for(;;) {
