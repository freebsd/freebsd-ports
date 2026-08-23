--- src/org/armedbear/lisp/LispThread.java.orig	2026-08-23 21:13:51 UTC
+++ src/org/armedbear/lisp/LispThread.java
@@ -129,9 +129,8 @@ public final class LispThread
       virtualThreadFactory
         = (ThreadFactory) factoryMethod.invoke(ofVirtual);
       newThread  
-        = virtualThreadFactory.getClass()
+        = ThreadFactory.class
         .getMethod("newThread", java.lang.Runnable.class);
-      newThread.setAccessible(true);
     } catch (Exception e) {
       if (virtualThreadingAvailable()) {
         Debug.trace("Failed to introspect virtual threading methods: " + e);
