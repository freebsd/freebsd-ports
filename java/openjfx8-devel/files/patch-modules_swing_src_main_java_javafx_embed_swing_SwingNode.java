--- modules/swing/src/main/java/javafx/embed/swing/SwingNode.java.orig	2019-07-22 18:58:46 UTC
+++ modules/swing/src/main/java/javafx/embed/swing/SwingNode.java
@@ -860,7 +860,7 @@ public class SwingNode extends Node {
             SwingFXUtils.runOnFxThread(() -> {
                 // On X11 grab is limited to a single XDisplay connection,
                 // so we can't delegate it to another GUI toolkit.
-                if (PlatformUtil.isLinux()) return;
+                if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return;
 
                 SwingNode swingNode = swingNodeRef.get();
                 if (swingNode != null) {
