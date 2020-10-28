--- modules/javafx.graphics/src/main/java/com/sun/javafx/tk/Toolkit.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/tk/Toolkit.java
@@ -186,6 +186,8 @@ public abstract class Toolkit {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isLinux()) {
             return DEFAULT_TOOLKIT;
+        } else if (PlatformUtil.isFreeBSD()) {
+            return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isIOS()) {
             return DEFAULT_TOOLKIT;
         } else if (PlatformUtil.isAndroid()) {
