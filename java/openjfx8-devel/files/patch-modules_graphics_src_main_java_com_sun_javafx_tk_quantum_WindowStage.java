--- modules/graphics/src/main/java/com/sun/javafx/tk/quantum/WindowStage.java.orig	2019-07-22 19:05:13 UTC
+++ modules/graphics/src/main/java/com/sun/javafx/tk/quantum/WindowStage.java
@@ -432,7 +432,7 @@ class WindowStage extends GlassStage {
         } else if (PlatformUtil.isWindows()) { //Windows Sized Icons
             SMALL_ICON_HEIGHT = 32;
             SMALL_ICON_WIDTH = 32;
-        } else if (PlatformUtil.isLinux()) { //Linux icons
+        } else if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) { //Linux icons
             SMALL_ICON_HEIGHT = 128;
             SMALL_ICON_WIDTH = 128;
         }
