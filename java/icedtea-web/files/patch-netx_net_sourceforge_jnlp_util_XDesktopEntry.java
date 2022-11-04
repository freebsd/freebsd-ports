--- netx/net/sourceforge/jnlp/util/XDesktopEntry.java.orig	2021-05-17 09:24:37 UTC
+++ netx/net/sourceforge/jnlp/util/XDesktopEntry.java
@@ -86,7 +86,7 @@ import net.sourceforge.jnlp.security.dialogresults.Acc
 
 public class XDesktopEntry implements GenericDesktopEntry {
  
-    public static final String JAVA_ICON_NAME = "javaws";
+    public static final String JAVA_ICON_NAME = "itweb-javaws";
 
     private JNLPFile file = null;
     private int iconSize = -1;
@@ -219,12 +219,12 @@ public class XDesktopEntry implements GenericDesktopEn
         if (exec != null) {
             return exec;
         }
-        String pathResult = findOnPath(new String[]{"javaws", System.getProperty("icedtea-web.bin.name")});
+        String pathResult = findOnPath(new String[]{"itweb-javaws", System.getProperty("icedtea-web.bin.name")});
         if (pathResult != null) {
             return pathResult;
         }
         
-        return "javaws";
+        return "itweb-javaws";
     }
     
     
