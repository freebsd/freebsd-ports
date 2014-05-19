--- jdk/src/share/classes/sun/applet/AppletViewerPanel.java
+++ jdk/src/share/classes/sun/applet/AppletViewerPanel.java
@@ -42,25 +42,25 @@
  *
  * @author      Arthur van Hoff
  */
-class AppletViewerPanel extends AppletPanel {
+public class AppletViewerPanel extends AppletPanel {
 
     /* Are we debugging? */
-    static boolean debug = false;
+    protected static boolean debug = false;
 
     /**
      * The document url.
      */
-    URL documentURL;
+    protected URL documentURL;
 
     /**
      * The base url.
      */
-    URL baseURL;
+    protected URL baseURL;
 
     /**
      * The attributes of the applet.
      */
-    Hashtable atts;
+    protected Hashtable<String,String> atts;
 
     /*
      * JDK 1.1 serialVersionUID
@@ -70,7 +70,7 @@
     /**
      * Construct an applet viewer and start the applet.
      */
-    AppletViewerPanel(URL documentURL, Hashtable atts) {
+    protected AppletViewerPanel(URL documentURL, Hashtable<String,String> atts) {
         this.documentURL = documentURL;
         this.atts = atts;
 
@@ -106,7 +106,7 @@
      * Get an applet parameter.
      */
     public String getParameter(String name) {
-        return (String)atts.get(name.toLowerCase());
+        return atts.get(name.toLowerCase());
     }
 
     /**
@@ -202,12 +202,12 @@
         return (AppletContext)getParent();
     }
 
-    static void debug(String s) {
+    protected static void debug(String s) {
         if(debug)
             System.err.println("AppletViewerPanel:::" + s);
     }
 
-    static void debug(String s, Throwable t) {
+    protected static void debug(String s, Throwable t) {
         if(debug) {
             t.printStackTrace();
             debug(s);
