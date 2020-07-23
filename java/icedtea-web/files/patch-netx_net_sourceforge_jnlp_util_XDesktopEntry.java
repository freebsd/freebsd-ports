--- netx/net/sourceforge/jnlp/util/XDesktopEntry.java.orig	2019-05-21 12:20:44.000000000 +0200
+++ netx/net/sourceforge/jnlp/util/XDesktopEntry.java	2019-06-19 14:33:09.000000000 +0200
@@ -86,7 +86,7 @@
 
 public class XDesktopEntry implements GenericDesktopEntry {
  
-    public static final String JAVA_ICON_NAME = "javaws";
+    public static final String JAVA_ICON_NAME = "itweb-javaws";
 
     private JNLPFile file = null;
     private int iconSize = -1;
@@ -219,12 +219,12 @@
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
     
     
