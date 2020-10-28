--- modules/javafx.controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.controls/src/main/java/com/sun/javafx/scene/control/behavior/TextInputControlBehavior.java
@@ -54,6 +54,7 @@ import javafx.scene.input.MouseEvent;
 import java.text.Bidi;
 import java.util.function.Predicate;
 
+import static com.sun.javafx.PlatformUtil.isFreeBSD;
 import static com.sun.javafx.PlatformUtil.isLinux;
 import static com.sun.javafx.PlatformUtil.isMac;
 import static com.sun.javafx.PlatformUtil.isWindows;
@@ -122,6 +123,7 @@ public abstract class TextInputControlBehavior<T exten
         final Predicate<KeyEvent> validWhenEditable = e -> !c.isEditable();
         final Predicate<KeyEvent> validOnWindows = e -> !PlatformUtil.isWindows();
         final Predicate<KeyEvent> validOnLinux = e -> !PlatformUtil.isLinux();
+        final Predicate<KeyEvent> validOnFreeBSD = e -> !PlatformUtil.isFreeBSD();
 
         KeyMapping cancelEditMapping;
         KeyMapping fireMapping;
@@ -550,7 +552,7 @@ public abstract class TextInputControlBehavior<T exten
 
     public void selectNextWord() {
         TextInputControl textInputControl = getNode();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isFreeBSD()) {
             textInputControl.selectEndOfNextWord();
         } else {
             textInputControl.selectNextWord();
@@ -599,7 +601,7 @@ public abstract class TextInputControlBehavior<T exten
 
     protected void nextWord() {
         TextInputControl textInputControl = getNode();
-        if (isMac() || isLinux()) {
+        if (isMac() || isLinux() || isFreeBSD()) {
             textInputControl.endOfNextWord();
         } else {
             textInputControl.nextWord();
