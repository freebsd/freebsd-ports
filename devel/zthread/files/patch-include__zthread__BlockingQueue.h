--- include/zthread/BlockingQueue.h.orig	2005-03-13 02:04:18 UTC
+++ include/zthread/BlockingQueue.h
@@ -83,7 +83,7 @@ namespace ZThread {
       /**
        * @see Queue::add(const T& item, unsigned long timeout)
        */
-      virtual bool add(T item, unsigned long timeout) {
+      virtual bool add(const T& item, unsigned long timeout) {
 
         try {
 
