--- modules/base/src/main/java/com/sun/javafx/PlatformUtil.java.orig	2017-07-22 15:59:03 UTC
+++ modules/base/src/main/java/com/sun/javafx/PlatformUtil.java
@@ -158,10 +158,10 @@ public class PlatformUtil {
     }
 
     /**
-     * Returns true if the operating system is a form of Linux or Solaris
+     * Returns true if the operating system is a form of Unix
      */
     public static boolean isUnix(){
-        return LINUX || SOLARIS;
+        return LINUX || SOLARIS || FREEBSD;
     }
 
     /**
