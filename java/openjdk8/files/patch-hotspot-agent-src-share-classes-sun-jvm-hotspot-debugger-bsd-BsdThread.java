--- ./hotspot/agent/src/share/classes/sun/jvm/hotspot/debugger/bsd/BsdThread.java.orig	2016-05-14 19:57:37.394543000 +0000
+++ ./hotspot/agent/src/share/classes/sun/jvm/hotspot/debugger/bsd/BsdThread.java	2016-05-14 20:47:09.600014000 +0000
@@ -61,7 +62,7 @@
     }
 
     public String toString() {
-        return Integer.toString(thread_id);
+        return Integer.toString(thread_id) + "/" + Long.toString(unique_thread_id);
     }
 
     public ThreadContext getContext() throws IllegalThreadStateException {
