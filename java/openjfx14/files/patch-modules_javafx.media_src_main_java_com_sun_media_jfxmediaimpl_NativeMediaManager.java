--- modules/javafx.media/src/main/java/com/sun/media/jfxmediaimpl/NativeMediaManager.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.media/src/main/java/com/sun/media/jfxmediaimpl/NativeMediaManager.java
@@ -110,7 +110,7 @@ public class NativeMediaManager {
                     NativeLibLoader.loadLibrary("glib-lite");
                 }
 
-                if (!HostUtils.isLinux() && !HostUtils.isIOS()) {
+                if (!HostUtils.isFreeBSD() && !HostUtils.isLinux() && !HostUtils.isIOS()) {
                     NativeLibLoader.loadLibrary("gstreamer-lite");
                 } else {
                     dependencies.add("gstreamer-lite");
