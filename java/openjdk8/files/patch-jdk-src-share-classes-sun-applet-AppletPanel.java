--- jdk/src/share/classes/sun/applet/AppletPanel.java
+++ jdk/src/share/classes/sun/applet/AppletPanel.java
@@ -68,7 +68,7 @@
     /**
      * The applet (if loaded).
      */
-    Applet applet;
+    protected Applet applet;
 
     /**
      * Applet will allow initialization.  Should be
@@ -162,7 +162,8 @@
      * Creates a thread to run the applet. This method is called
      * each time an applet is loaded and reloaded.
      */
-    synchronized void createAppletThread() {
+	//Overridden by NetxPanel.
+    protected synchronized void createAppletThread() {
         // Create a thread group for the applet, and start a new
         // thread to load the applet.
         String nm = "applet-" + getCode();
@@ -306,7 +307,7 @@
     /**
      * Get an event from the queue.
      */
-    synchronized AppletEvent getNextEvent() throws InterruptedException {
+    protected synchronized AppletEvent getNextEvent() throws InterruptedException {
         while (queue == null || queue.isEmpty()) {
             wait();
         }
@@ -692,7 +693,8 @@
      * applet event processing so that it can be gracefully interrupted from
      * things like HotJava.
      */
-    private void runLoader() {
+	//Overridden by NetxPanel.
+    protected void runLoader() {
         if (status != APPLET_DISPOSE) {
             showAppletStatus("notdisposed");
             return;
