--- modules/base/src/main/java/com/sun/javafx/PlatformUtil.java.orig	2017-09-08 16:56:55 UTC
+++ modules/base/src/main/java/com/sun/javafx/PlatformUtil.java
@@ -69,6 +69,7 @@ public class PlatformUtil {
     private static final boolean WINDOWS_7_OR_LATER = WINDOWS && versionNumberGreaterThanOrEqualTo(6.1f);
     private static final boolean MAC = os.startsWith("Mac");
     private static final boolean LINUX = os.startsWith("Linux") && !ANDROID;
+    private static final boolean FREEBSD = os.startsWith("FreeBSD");
     private static final boolean SOLARIS = os.startsWith("SunOS");
     private static final boolean IOS = os.startsWith("iOS");
 
@@ -124,6 +125,13 @@ public class PlatformUtil {
         return LINUX;
     }
 
+    /**
+     * Returns true if the operating system is a form of FreeBSD.
+     */
+    public static boolean isFreeBSD(){
+        return FREEBSD;
+    }
+
     public static boolean useEGL() {
         return useEGL;
     }
@@ -150,10 +158,10 @@ public class PlatformUtil {
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
