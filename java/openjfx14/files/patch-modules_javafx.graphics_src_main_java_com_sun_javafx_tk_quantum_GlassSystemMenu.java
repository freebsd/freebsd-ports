--- modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/GlassSystemMenu.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/java/com/sun/javafx/tk/quantum/GlassSystemMenu.java
@@ -313,13 +313,13 @@ class GlassSystemMenu implements TKSystemMenu {
         } else if (accelerator instanceof KeyCodeCombination) {
             KeyCodeCombination kcc  = (KeyCodeCombination)accelerator;
             KeyCode            code = kcc.getCode();
-            assert PlatformUtil.isMac() || PlatformUtil.isLinux();
+            assert PlatformUtil.isMac() || PlatformUtil.isLinux() || PlatformUtil.isFreeBSD();
             int modifier = glassModifiers(kcc);
             if (PlatformUtil.isMac()) {
                 int finalCode = code.isLetterKey() ? code.getChar().toUpperCase().charAt(0)
                         : code.getCode();
                 glassSubMenuItem.setShortcut(finalCode, modifier);
-            } else if (PlatformUtil.isLinux()) {
+            } else if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) {
                 String lower = code.getChar().toLowerCase();
                 if ((modifier & KeyEvent.MODIFIER_CONTROL) != 0) {
                     glassSubMenuItem.setShortcut(lower.charAt(0), modifier);
@@ -348,14 +348,14 @@ class GlassSystemMenu implements TKSystemMenu {
             ret += KeyEvent.MODIFIER_ALT;
         }
         if (kcc.getShortcut() == KeyCombination.ModifierValue.DOWN) {
-            if (PlatformUtil.isLinux()) {
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) {
                 ret += KeyEvent.MODIFIER_CONTROL;
             } else if (PlatformUtil.isMac()) {
                 ret += KeyEvent.MODIFIER_COMMAND;
             }
         }
         if (kcc.getMeta() == KeyCombination.ModifierValue.DOWN) {
-            if (PlatformUtil.isLinux()) {
+            if (PlatformUtil.isLinux() || PlatformUtil.isFreeBSD()) {
                 ret += KeyEvent.MODIFIER_WINDOWS;   // RT-19326 - Linux shortcut support
             } else if (PlatformUtil.isMac()) {
                 ret += KeyEvent.MODIFIER_COMMAND;
