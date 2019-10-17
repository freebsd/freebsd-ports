--- jdk/src/solaris/classes/sun/nio/fs/BsdNativeDispatcher.java.orig	2019-10-17 19:49:41 UTC
+++ jdk/src/solaris/classes/sun/nio/fs/BsdNativeDispatcher.java
@@ -69,6 +69,11 @@ class BsdNativeDispatcher extends UnixNativeDispatcher
     private static native void initIDs();
 
     static {
+         AccessController.doPrivileged(new PrivilegedAction<Void>() {
+             public Void run() {
+                 System.loadLibrary("nio");
+                 return null;
+         }});
          initIDs();
     }
 }
