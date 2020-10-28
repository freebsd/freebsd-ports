--- modules/javafx.swing/src/main/java/javafx/embed/swing/JFXPanel.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.swing/src/main/java/javafx/embed/swing/JFXPanel.java
@@ -1043,7 +1043,7 @@ public class JFXPanel extends JComponent {
         public boolean grabFocus() {
             // On X11 grab is limited to a single XDisplay connection,
             // so we can't delegate it to another GUI toolkit.
-            if (PlatformUtil.isLinux()) return true;
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return true;
 
             invokeOnClientEDT(() -> {
                 Window window = SwingUtilities.getWindowAncestor(JFXPanel.this);
@@ -1059,7 +1059,7 @@ public class JFXPanel extends JComponent {
         public void ungrabFocus() {
             // On X11 grab is limited to a single XDisplay connection,
             // so we can't delegate it to another GUI toolkit.
-            if (PlatformUtil.isLinux()) return;
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) return;
 
             invokeOnClientEDT(() -> {
                 Window window = SwingUtilities.getWindowAncestor(JFXPanel.this);
