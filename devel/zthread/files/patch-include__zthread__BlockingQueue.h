--- ./include/zthread/BlockingQueue.h.orig	2005-03-12 21:04:18.000000000 -0500
+++ ./include/zthread/BlockingQueue.h	2009-04-23 15:03:09.000000000 -0400
@@ -83,7 +83,7 @@
       /**
        * @see Queue::add(const T& item, unsigned long timeout)
        */
-      virtual bool add(T item, unsigned long timeout) {
+      virtual bool add(const T& item, unsigned long timeout) {
 
         try {
 
