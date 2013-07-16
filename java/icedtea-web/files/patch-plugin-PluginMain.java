--- plugin/icedteanp/java/sun/applet/PluginMain.java	Tue Jun 18 15:57:01 2013 -0400
+++ plugin/icedteanp/java/sun/applet/PluginMain.java	Thu Jun 20 15:20:57 2013 +0200
@@ -72,6 +72,8 @@
 import java.net.ProxySelector;
 import java.util.Enumeration;
 import java.util.Properties;
+import sun.awt.AppContext;
+import sun.awt.SunToolkit;
 
 import net.sourceforge.jnlp.config.DeploymentConfiguration;
 import net.sourceforge.jnlp.runtime.JNLPRuntime;
@@ -94,6 +96,9 @@
      */
     public static void main(String args[])
             throws IOException {
+        if (AppContext.getAppContext() == null) {
+            SunToolkit.createNewAppContext();
+        }
         if (args.length != 2 || !(new File(args[0]).exists()) || !(new File(args[1]).exists())) {
             System.err.println("Invalid pipe names provided. Refusing to proceed.");
             System.exit(1);

