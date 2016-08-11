--- java/src/charva/awt/Window.java.orig	2016-06-20 12:40:44 UTC
+++ java/src/charva/awt/Window.java
@@ -156,13 +156,21 @@ public class Window
          */
         SyncQueue.getInstance().postEvent(new SyncEvent(this));
 
-        if (_dispatchThreadRunning)
-            run();
-        else {
-            _dispatchThreadRunning = true;
-            Thread dispatchThread = new Thread(this);
-            dispatchThread.setName("event dispatcher");
-            dispatchThread.start();
+        if (_dispatchThread != null) {
+            if (Thread.currentThread() == _dispatchThread) {
+        	// we are in the EDT, we must manage events
+        	run();
+            } else {
+        	// we are not the EDT, let's wait for him to ask us to close
+                synchronized (this) {
+                    while (!_windowClosed)
+                        try { wait(); } catch (InterruptedException e) { }
+                }
+            }
+        } else {
+            _dispatchThread = new Thread(this);
+            _dispatchThread.setName("event dispatcher");
+            _dispatchThread.start();
 
             /* If "charva.script.playback" is defined, we start up
              * a thread for playing back the script. Keys from both the
@@ -270,7 +278,10 @@ public class Window
              */
             if (we.getID() == AWTEvent.WINDOW_CLOSING) {
 
-                we.getWindow()._windowClosed = true;
+        	synchronized (we.getWindow()) {
+        	    we.getWindow()._windowClosed = true;
+        	    we.getWindow().notify();
+        	}
 
                 /* Remove this window from the list of those displayed,
                  * and blank out the screen area where the window was
@@ -407,10 +418,10 @@ public class Window
 
     private Window _owner;
     protected Toolkit _term;
-    private boolean _windowClosed = false;
+    private volatile boolean _windowClosed = false;
 
     private Vector _windowListeners = null;
 
-    private static boolean _dispatchThreadRunning = false;
+    private static Thread _dispatchThread = null;
 
 }
