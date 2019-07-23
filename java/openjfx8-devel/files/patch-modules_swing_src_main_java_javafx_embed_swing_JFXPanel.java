--- modules/swing/src/main/java/javafx/embed/swing/JFXPanel.java.orig	2019-07-22 18:59:20 UTC
+++ modules/swing/src/main/java/javafx/embed/swing/JFXPanel.java
@@ -995,7 +995,7 @@ public class JFXPanel extends JComponent {
         public boolean grabFocus() {
             // On X11 grab is limited to a single XDisplay connection,
             // so we can't delegate it to another GUI toolkit.
-            if (PlatformUtil.isLinux()) return true;
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return true;
 
             invokeOnClientEDT(() -> {
                 Window window = SwingUtilities.getWindowAncestor(JFXPanel.this);
@@ -1013,7 +1013,7 @@ public class JFXPanel extends JComponent {
         public void ungrabFocus() {
             // On X11 grab is limited to a single XDisplay connection,
             // so we can't delegate it to another GUI toolkit.
-            if (PlatformUtil.isLinux()) return;
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return;
 
             invokeOnClientEDT(() -> {
                 Window window = SwingUtilities.getWindowAncestor(JFXPanel.this);
