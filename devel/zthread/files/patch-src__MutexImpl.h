--- ./src/MutexImpl.h.orig	2005-03-12 22:59:15.000000000 -0500
+++ ./src/MutexImpl.h	2009-04-23 15:03:09.000000000 -0400
@@ -153,7 +153,7 @@
 
       _owner = self;
 
-      ownerAcquired(self);
+      this->ownerAcquired(self);
       
     }
 
@@ -164,7 +164,7 @@
       _waiters.insert(self);
       m.acquire();
 
-      waiterArrived(self);
+      this->waiterArrived(self);
 
       {        
       
@@ -173,7 +173,7 @@
       
       }
 
-      waiterDeparted(self);
+      this->waiterDeparted(self);
 
       m.release();
         
@@ -192,7 +192,7 @@
           assert(_owner == 0);
           _owner = self;    
 
-          ownerAcquired(self);
+          this->ownerAcquired(self);
 
           break;
         
@@ -236,7 +236,7 @@
 
       _owner = self;
 
-      ownerAcquired(self);
+      this->ownerAcquired(self);
       
     }
 
@@ -253,7 +253,7 @@
       
         m.acquire();
 
-        waiterArrived(self);
+        this->waiterArrived(self);
       
         {
         
@@ -262,7 +262,7 @@
         
         }
 
-        waiterDeparted(self);
+        this->waiterDeparted(self);
       
         m.release();
         
@@ -284,7 +284,7 @@
           assert(0 == _owner);
           _owner = self;
 
-          ownerAcquired(self);
+          this->ownerAcquired(self);
         
           break;
         
@@ -326,7 +326,7 @@
 
     _owner = 0;
 
-    ownerReleased(impl);
+    this->ownerReleased(impl);
   
     // Try to find a waiter with a backoff & retry scheme
     for(;;) {
