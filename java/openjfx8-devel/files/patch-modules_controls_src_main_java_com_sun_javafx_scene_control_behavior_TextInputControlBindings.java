--- modules/controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBindings.java.orig	2019-07-22 19:06:01 UTC
+++ modules/controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBindings.java
@@ -134,7 +134,7 @@ public class TextInputControlBindings {
             BINDINGS.add(new KeyBinding(KP_RIGHT, KEY_PRESSED,   "SelectRightWord").ctrl().shift());
             BINDINGS.add(new KeyBinding(A, KEY_PRESSED,          "SelectAll").ctrl());
             BINDINGS.add(new KeyBinding(BACK_SLASH, KEY_PRESSED, "Unselect").ctrl());
-            if (PlatformUtil.isLinux()) {
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) {
                 BINDINGS.add(new KeyBinding(Z, KEY_PRESSED,          "Undo").ctrl());
                 BINDINGS.add(new KeyBinding(Z, KEY_PRESSED,          "Redo").ctrl().shift());
             } else {  // Windows
