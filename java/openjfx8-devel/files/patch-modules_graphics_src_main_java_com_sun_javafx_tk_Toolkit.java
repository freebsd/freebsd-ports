--- modules/graphics/src/main/java/com/sun/javafx/tk/Toolkit.java.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/java/com/sun/javafx/tk/Toolkit.java
@@ -185,6 +185,8 @@ public abstract class Toolkit {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isLinux()) {
             return DEFAULT_TOOLKIT;
+        } else if (PlatformUtil.isFreeBSD()) {
+            return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isIOS()) {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isAndroid()) {
