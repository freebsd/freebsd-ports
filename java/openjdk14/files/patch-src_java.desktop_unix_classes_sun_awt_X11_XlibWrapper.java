--- src/java.desktop/unix/classes/sun/awt/X11/XlibWrapper.java.orig	2020-04-17 22:35:42 UTC
+++ src/java.desktop/unix/classes/sun/awt/X11/XlibWrapper.java
@@ -529,7 +529,7 @@ static native String XSetLocaleModifiers(String modifi
           display   Specifies the connection to the X server.
           onoff     Specifies a Boolean value that indicates whether to enable or disable synchronization.
      */
-    static native int XSynchronize(long display, boolean onoff);
+    static native long XSynchronize(long display, boolean onoff);
 
     /**
      * Extracts an X event that can be processed in a secondary loop.
