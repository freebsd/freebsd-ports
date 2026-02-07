--- modules/javafx.media/src/main/java/com/sun/media/jfxmediaimpl/HostUtils.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.media/src/main/java/com/sun/media/jfxmediaimpl/HostUtils.java
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
