--- modules/javafx.swing/src/main/java/javafx/embed/swing/SwingNode.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.swing/src/main/java/javafx/embed/swing/SwingNode.java
@@ -807,7 +807,7 @@ public class SwingNode extends Node {
     private void ungrabFocus(boolean postUngrabEvent) {
         // On X11 grab is limited to a single XDisplay connection,
         // so we can't delegate it to another GUI toolkit.
-        if (PlatformUtil.isLinux()) return;
+        if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return;
 
         if (grabbed &&
             getScene() != null &&
