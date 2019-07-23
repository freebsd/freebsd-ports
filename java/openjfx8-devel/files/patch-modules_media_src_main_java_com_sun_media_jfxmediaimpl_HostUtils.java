--- modules/media/src/main/java/com/sun/media/jfxmediaimpl/HostUtils.java.orig	2019-07-22 19:01:46 UTC
+++ modules/media/src/main/java/com/sun/media/jfxmediaimpl/HostUtils.java
@@ -66,6 +66,10 @@ public class HostUtils {
         return osName.startsWith("linux");
     }
 
+    public static boolean isFreeBSD() {
+        return osName.startsWith("freebsd");
+    }
+
     public static boolean isIOS() {
         return osName.startsWith("ios");
     }
