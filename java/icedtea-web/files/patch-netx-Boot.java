--- netx/net/sourceforge/jnlp/runtime/Boot.java	Tue Jun 18 15:57:01 2013 -0400
+++ netx/net/sourceforge/jnlp/runtime/Boot.java	Thu Jun 20 15:20:57 2013 +0200
@@ -35,6 +35,8 @@
 import net.sourceforge.jnlp.cache.UpdatePolicy;
 import net.sourceforge.jnlp.security.viewer.CertificateViewer;
 import net.sourceforge.jnlp.services.ServiceUtil;
+import sun.awt.AppContext;
+import sun.awt.SunToolkit;
 
 /**
  * This is the main entry point for the JNLP client.  The main
@@ -113,6 +115,9 @@
      * Launch the JNLP file specified by the command-line arguments.
      */
     public static void main(String[] argsIn) {
+        if (AppContext.getAppContext() == null) {
+            SunToolkit.createNewAppContext();
+        }
         args = argsIn;
 
         if (null != getOption("-viewer")) {
