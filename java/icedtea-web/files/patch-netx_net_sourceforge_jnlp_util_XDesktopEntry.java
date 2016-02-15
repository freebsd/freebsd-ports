--- netx/net/sourceforge/jnlp/util/XDesktopEntry.java.orig	2016-02-03 13:47:43 UTC
+++ netx/net/sourceforge/jnlp/util/XDesktopEntry.java
@@ -78,7 +78,7 @@ import net.sourceforge.jnlp.security.dia
  */
 public class XDesktopEntry {
 
-    public static final String JAVA_ICON_NAME = "javaws";
+    public static final String JAVA_ICON_NAME = "itweb-javaws";
 
     private JNLPFile file = null;
     private int iconSize = -1;
@@ -202,14 +202,14 @@ public class XDesktopEntry {
         //Shortcut executes the jnlp as it was with system preferred java. It should work fine offline
         //absolute - works in case of self built
         String exec = System.getProperty("icedtea-web.bin.location");
-        String pathResult = findOnPath(new String[]{"javaws", System.getProperty("icedtea-web.bin.name")});
+        String pathResult = findOnPath(new String[]{"itweb-javaws", System.getProperty("icedtea-web.bin.name")});
         if (pathResult != null) {
             return pathResult;
         }
         if (exec != null) {
             return exec;
         }
-        return "javaws";
+        return "itweb-javaws";
     }
     
     
