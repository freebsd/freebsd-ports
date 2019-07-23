--- modules/media/src/main/java/com/sun/media/jfxmediaimpl/NativeMediaManager.java.orig	2019-07-22 19:02:57 UTC
+++ modules/media/src/main/java/com/sun/media/jfxmediaimpl/NativeMediaManager.java
@@ -108,7 +108,7 @@ public class NativeMediaManager {
                     NativeLibLoader.loadLibrary("glib-lite");
                 }
 
-                if (!HostUtils.isLinux() && !HostUtils.isIOS()) {
+                if (!HostUtils.isFreeBSD() && !HostUtils.isLinux() && !HostUtils.isIOS()) {
                     NativeLibLoader.loadLibrary("gstreamer-lite");
                 }
 
